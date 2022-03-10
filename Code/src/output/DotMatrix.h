#pragma once
#include <Arduino.h>
#include <LedControl.h>

// Standard window stuff
#define PIXELS_PER_DISPLAY_X    8
#define PIXELS_PER_DISPLAY_Y    8

// Top window
#define NUM_DISPLAYS_TOP        4
#define DIN_PIN_TOP             11
#define CLK_PIN_TOP             12
#define CS_PIN_TOP              10

// Bottom window
#define NUM_DISPLAYS_BOTTOM     4
#define DIN_PIN_BOTTOM          6
#define CLK_PIN_BOTTOM          7
#define CS_PIN_BOTTOM           5

// Combined windows
#define NUM_DISPLAYS            NUM_DISPLAYS_TOP + NUM_DISPLAYS_BOTTOM
#define NUM_DISPLAYS_X          4
#define NUM_DISPLAYS_Y          2


class DotMatrix
{
private:
    LedControl* m_ledControllerTop;
    LedControl* m_ledControllerBottom;

public:
    DotMatrix();
    ~DotMatrix();

    void setDisplayBrightness(unsigned brightness);
    void setDisplayBrightness(unsigned brightness, unsigned display);

    void setPixel(unsigned x, unsigned y, bool activate);
    void setPixel(unsigned x, unsigned y, unsigned display, bool activate);

    void clear();
    void clear(unsigned display);

    void setPowerSavingMode(bool inBatteryMode);
    void setPowerSavingMode(bool inBatteryMode, unsigned display);
};