#include "DotMatrix.h"
#include "../Log.h"

DotMatrix::DotMatrix()
{
    m_ledControllerTop = new LedControl(DIN_PIN_TOP, CLK_PIN_TOP, CS_PIN_TOP, NUM_DISPLAYS_TOP);
    m_ledControllerBottom = new LedControl(DIN_PIN_BOTTOM, CLK_PIN_BOTTOM, CS_PIN_BOTTOM, NUM_DISPLAYS_BOTTOM);

    setPowerSavingMode(false);
}

DotMatrix::~DotMatrix()
{
    clear();
    setPowerSavingMode(true);
    delete m_ledControllerTop;
    delete m_ledControllerBottom;
}

void DotMatrix::setDisplayBrightness(unsigned brightness)
{
    for (int i = 0; i < NUM_DISPLAYS_X; i++)
    {
        m_ledControllerTop->setIntensity(i, brightness);
        m_ledControllerBottom->setIntensity(i, brightness);
    }
}

void DotMatrix::setDisplayBrightness(unsigned brightness, unsigned display)
{
    if (display >= NUM_DISPLAYS)
    {
        LOG_ERROR("Given display does not exist!");
        return;
    }

    if (display > NUM_DISPLAYS_X - 1)
    {
        display = display - NUM_DISPLAYS_X;
        m_ledControllerBottom->setIntensity(display, brightness);
    } else
    {
        m_ledControllerTop->setIntensity(display, brightness);
    }    
}

void DotMatrix::setPixel(unsigned x, unsigned y, bool activate)
{
    if (x > NUM_DISPLAYS_X * PIXELS_PER_DISPLAY_X - 1 || y > NUM_DISPLAYS_Y * PIXELS_PER_DISPLAY_Y - 1)
    {
        LOG_ERROR("Given pixel value is out of range!");
        return;
    }

    int displayX = x / PIXELS_PER_DISPLAY_X;
    x = x - (PIXELS_PER_DISPLAY_X * displayX);

    if (y > PIXELS_PER_DISPLAY_Y - 1)
    {
        y = y - PIXELS_PER_DISPLAY_Y;

        setPixel(x, y, displayX + NUM_DISPLAYS_X, activate);
    } else
    {
        setPixel(x, y, displayX, activate);
    }
}

void DotMatrix::setPixel(unsigned x, unsigned y, unsigned display, bool activate)
{
    if (display >= NUM_DISPLAYS)
    {
        LOG_ERROR("Given display does not exist!");
        return;
    }

    if (x > PIXELS_PER_DISPLAY_X - 1 || y > PIXELS_PER_DISPLAY_Y - 1)
    {
        LOG_ERROR("Given pixel value is out of range!");
        return;
    }

    int invertedX = (PIXELS_PER_DISPLAY_X - 1) - x;

    if (display > NUM_DISPLAYS_X - 1)
    {
        display = display - NUM_DISPLAYS_X;
        m_ledControllerTop->setLed(display, y, invertedX, activate);
    } else
    {
        m_ledControllerBottom->setLed(display, y, invertedX, activate);
    } 
}

void DotMatrix::clear()
{
    for (int i = 0; i < NUM_DISPLAYS_X; i++)
    {
        m_ledControllerTop->clearDisplay(i);
        m_ledControllerBottom->clearDisplay(i);
    }
}

void DotMatrix::clear(unsigned display)
{
    if (display >= NUM_DISPLAYS)
    {
        LOG_ERROR("Given display does not exist!");
        return;
    }

    if (display > NUM_DISPLAYS_X - 1)
    {
        display = display - NUM_DISPLAYS_X;
        m_ledControllerBottom->clearDisplay(display);
    } else
    {
        m_ledControllerTop->clearDisplay(display);
    } 
}

void DotMatrix::setPowerSavingMode(bool inBatteryMode)
{
    for (int i = 0; i < NUM_DISPLAYS_X; i++)
    {
        m_ledControllerTop->shutdown(i, inBatteryMode);
        m_ledControllerBottom->shutdown(i, inBatteryMode);
    }
}

void DotMatrix::setPowerSavingMode(bool inBatteryMode, unsigned display)
{
    if (display >= NUM_DISPLAYS)
    {
        LOG_ERROR("Given display does not exist!");
        return;
    }

    if (display > NUM_DISPLAYS_X - 1)
    {
        display = display - NUM_DISPLAYS_X;
        m_ledControllerBottom->shutdown(display, inBatteryMode);
    } else
    {
        m_ledControllerTop->shutdown(display, inBatteryMode);
    }
}