//
// Created by fille
#include "oledScreen.h"

#define frameDelay 42

oledScreen::oledScreen(Adafruit_SSD1306& display) {
    : _display(display){}

    void oledScreen::begin() {
        _display.clearDisplay();
    }
    void oledScreen::update() {
        if (millis() - _lastFrame < frameDelay) return;
        _lastFrame = millis();
        playAnimation();
    }
    void oledScreen::playAnimation() {
        _display.clearDisplay();
        //bitmap
        _display.display();
    }
}
