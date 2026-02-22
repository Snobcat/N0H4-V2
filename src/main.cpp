#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#include "oledScreen.h"
// Define section
#define SCREEN_W 128
#define SCREEN_H 64
#define OLED_RESET -1
#define OLED_SDA D2
#define OLED_SCL D1
#define EXE_DELAY 1000

// OLED, PCA, RTC objects
Adafruit_SSD1306 display(SCREEN_W, SCREEN_H, &Wire, OLED_RESET);
oledScreen playAnimation(display);


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

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
// Timing
unsigned long lastMillis = 0;
bool tiltState = false;
bool lastTiltState = false;
unsigned long lastTiltchange = 0;
const unsigned long debounceMs = 50;
bool readTiltDebounced() {
    bool reading = (digitalRead(tiltPin) == LOW);
    if (reading != lastTiltState) {
        lastTiltchange = millis();
        lastTiltState = reading;
    }
    if (millis() - lastTiltchange > debounceMs) {
        tiltState = reading;
    }
    return tiltState;
}

void setup() {
    Serial.begin(115200);
    Wire.begin(OLED_SDA, OLED_SCL);
    pinMode(tiltPin, INPUT_PULLUP);

    // Initialize display
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(DISP_ERR);
        while (1);
    }
    playAnimation.begin();



}
bool lastTilt = false;

void loop() {
    bool tilted = readTiltDebounced();
    if (tilted && !lastTiltState) {
        playAnimation.begin();
    }
    if (tilted) {
        playAnimation.update();
    }
    lastTilt = tilted;

playAnimation.update();



    // Mood logic
    switch (current_mood) {
        case IDLE:
            break;
        case HAPPY:
            break;
        case ANGRY:
            break;
    }
}