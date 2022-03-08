#include "LedWindow.h"
#include "../Log.h"

LedWindow::LedWindow(unsigned dinPin, unsigned clkPin, unsigned csPin, unsigned numDisplaysX, unsigned numDisplaysY)
    : m_numDisplays(numDisplaysX * numDisplaysY), m_numDisplaysX(numDisplaysX), m_numDisplaysY(numDisplaysY)
{
    m_ledController = new LedControl(dinPin, clkPin, csPin, m_numDisplays);

    setPowerSavingMode(false);
}

LedWindow::~LedWindow()
{
    clear();
    setPowerSavingMode(true);
    delete m_ledController;
}

void LedWindow::setDisplayBrightness(unsigned brightness)
{
    for (int i = 0; i < m_numDisplays; i++)
    {
        m_ledController->setIntensity(i, brightness);
    }
}

void LedWindow::setDisplayBrightness(unsigned brightness, unsigned display)
{
    if (display >= m_numDisplays)
    {
        LOG_ERROR("Given display does not exist!");
        return;
    }

    m_ledController->setIntensity(display, brightness);
}

void LedWindow::setPixel(unsigned x, unsigned y, bool activate)
{
    if (x > (8 * m_numDisplaysX - 1) || y > (8 * m_numDisplaysY - 1))
    {
        LOG_ERROR("Given pixel value is out of range!");
        return;
    }

    // TODO 
}

void LedWindow::setPixel(unsigned x, unsigned y, unsigned display, bool activate)
{
    if (display >= m_numDisplays)
    {
        LOG_ERROR("Given display does not exist!");
        return;
    }

    if (x > 7 || y > 7)
    {
        LOG_ERROR("Given pixel value is out of range!");
        return;
    }

    m_ledController->setLed(display, y, x, activate);
}

void LedWindow::clear()
{
    for (int i = 0; i < m_numDisplays; i++)
    {
        m_ledController->clearDisplay(i);
    }
}

void LedWindow::clear(unsigned display)
{
    if (display >= m_numDisplays)
    {
        LOG_ERROR("Given display does not exist!");
        return;
    }

    m_ledController->clearDisplay(display);
}

void LedWindow::setPowerSavingMode(bool inBatteryMode)
{
    for (int i = 0; i < m_numDisplays; i++)
    {
        m_ledController->shutdown(i, inBatteryMode);
    }
}

void LedWindow::setPowerSavingMode(bool inBatteryMode, unsigned display)
{
    if (display >= m_numDisplays)
    {
        LOG_ERROR("Given display does not exist!");
        return;
    }

    m_ledController->shutdown(display, inBatteryMode);
}