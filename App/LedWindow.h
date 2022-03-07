#pragma once

#include <LedControl.h>

class LedWindow
{
private:
    LedControl* m_ledController;

    unsigned m_numDisplays;
    unsigned m_numDisplaysX;
    unsigned m_numDisplaysY;

public:
    LedWindow(unsigned dinPin, unsigned clkPin, unsigned csPin, unsigned numDisplaysX, unsigned numDisplaysY);
    ~LedWindow();

    void setDisplayBrightness(unsigned brightness);
    void setDisplayBrightness(unsigned brightness, unsigned display);

    void setPixel(unsigned x, unsigned y, bool activate = true);
    void setPixel(unsigned x, unsigned y, unsigned display, bool activate = true);

    void clear();
    void clear(unsigned display);

    void setPowerSavingMode(bool inBatteryMode);
    void setPowerSavingMode(bool inBatteryMode, unsigned display);
};