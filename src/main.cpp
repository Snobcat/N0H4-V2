#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>

// Define section
#define SCREEN_W 128
#define SCREEN_H 64
#define OLED_RESET -1
#define OLED_SDA D2
#define OLED_SCL D1
#define EXE_DELAY 1000

// OLED, PCA, RTC objects
Adafruit_SSD1306 display(SCREEN_W, SCREEN_H, &Wire, OLED_RESET);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
RTC_DS1307 rtc;

// Mood enum
enum Moods {
    IDLE,
    HAPPY,
    ANGRY
};
Moods current_mood = IDLE;

// Pins
const uint8_t tiltPin = D5;
const uint8_t trigPin = D6;
const uint8_t echoPin = D7;
const uint8_t buzzerPin = D0;

// PCA pins
const uint8_t servo1Pin = 0;
const uint8_t servo2Pin = 1;
const uint8_t rgbRedPin = 2;
const uint8_t rgbGreenPin = 3;
const uint8_t rgbBluePin = 4;

// Error codes
const unsigned short int DISP_ERR = 2;
const unsigned short int RTC_ERR  = 3;

// Timing
unsigned long lastMillis = 0;

void setup() {
    Serial.begin(115200);
    Wire.begin(OLED_SDA, OLED_SCL);

    // Initialize display
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(DISP_ERR);
        while (1);
    }

    // Initialize RTC
    if (!rtc.begin()) {
        Serial.println(RTC_ERR);
        while (1);
    }
    if (!rtc.isrunning()) {
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }

    // Optional: show a startup circle (will disappear after first loop)
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.drawCircle(SCREEN_W/2, SCREEN_H/2, 3, WHITE);
    display.display();
}

void loop() {
    unsigned long currentMillis = millis();

    // Update display at interval
    if (currentMillis - lastMillis >= EXE_DELAY) {
        lastMillis = currentMillis;

        DateTime now = rtc.now();

        // Clear the display before writing new text (removes circle)
        display.clearDisplay();

        display.setCursor(0, 0);
        display.setTextSize(1);
        display.setTextColor(WHITE);

        // Print date
        display.print(now.year(), DEC);
        display.print('/');
        display.print(now.month(), DEC);
        display.print('/');
        display.println(now.day(), DEC);

        // Print time
        display.print(now.hour(), DEC);
        display.print(':');
        display.print(now.minute(), DEC);
        display.print(':');
        display.println(now.second(), DEC);

        display.display();
    }

    // Mood logic placeholder
    switch (current_mood) {
        case IDLE:
            break;
        case HAPPY:
            break;
        case ANGRY:
            break;
    }
}