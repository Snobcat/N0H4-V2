//
// Created by fille on 2026-02-22.
//
#pragma once
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#ifndef N0H4V2_OLEDSCREEN_H
#define N0H4V2_OLEDSCREEN_H


class oledScreen {
public:
    oledScreen(Adafruit_SSD1306& display);
    void begin();
    void update();
    void playAnimation();
    private:
    Adafruit_SSD1306& _display;
    unsigned long _lastFrame = 0;
    uint8_t _frame = 0;
};


#endif //N0H4V2_OLEDSCREEN_H