#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include <atomic>
#include <SPI.h>
//Define section
#define screenW 128
#define screenH 64
#define oledSDA D2
#define oledSCL D1
#define EXE_INTERVAL 2000
#define EXE_DELAY 1000
Adafruit_SSD1306 display(screenW, screenH, &Wire);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
RTC_DS1307 rtc;
enum Moods {
    IDLE,
    HAPPY,
    ANGRY
};
Moods current_mood = IDLE;

//Pins
//some shared pins
const uint8_t sdaPin = D2;
const uint8_t sclPin = D1;

const uint8_t tiltPin = D5;
const uint8_t trigPin = D6;
const uint8_t echoPin = D7;
const uint8_t buzzerPin = D0;
//PCA pins
const uint8_t servo1Pin = 0;
const uint8_t servo2Pin = 1;
const uint8_t rgbRedPin = 2;
const uint8_t rgbGreenPin = 3;
const uint8_t rgbBluePin = 4;
unsigned short int disperr = 2;
unsigned short int rtcerr = 3;
unsigned long lastMillis = 0;
void setup() {
    unsigned long currentMillis = millis();
// write your initialization code here
    Wire.begin(oledSDA, oledSCL);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C) || rtc.begin()) {
        disperr;
        rtcerr;
        while (1);
    }
    if (!rtc.isrunning()) {
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.drawCircle(screenW/2, screenH/2, 3, WHITE);
    display.display();
    if (currentMillis - lastMillis >= EXE_INTERVAL) {
        lastMillis = currentMillis;
    }

}

void loop() {
// write your code here
    unsigned long currentMillis = millis();
    DateTime now = rtc.now();
    display.clearDisplay();
    display.setCursor(screenW/2, screenH/2);
    display.print(now.year(), DEC);
    display.print('/');
    display.print(now.month(), DEC);
    display.print('/');
    display.println(now.day(), DEC);
    display.print(now.hour(), DEC);
    display.print(':');
    display.print(now.minute(), DEC);
    display.print(':');
    display.print(now.second(), DEC);
    if (currentMillis - lastMillis >= EXE_DELAY) {
        lastMillis = currentMillis;
    }

    switch (current_mood) {
            case IDLE:

            break;
            case HAPPY:

            break;
            case ANGRY:

            break;
    }
}