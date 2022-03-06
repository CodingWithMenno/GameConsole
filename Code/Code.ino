#include "Log.h"
#include "LedWindow.h"
#include "Button.h"

#define SERIAL_BAUD     9600

// Led Window settings
#define NUM_DISPLAYS_X  1
#define NUM_DISPLAYS_Y  1
#define DIN_PIN         11
#define CLK_PIN         13
#define CS_PIN          3

LedWindow* ledWindow;

Button* button;

void setup() 
{
  Log::Init(SERIAL_BAUD);

  ledWindow = new LedWindow(DIN_PIN, CLK_PIN, CS_PIN, NUM_DISPLAYS_X, NUM_DISPLAYS_Y);
  ledWindow->setDisplayBrightness(4);

  button = new Button(2);
}

void loop() 
{
  ledWindow->clear();

  if (button->isPressed())
  {
    ledWindow->setPixel(7, 4, 0, true);
  }
}

void shutdown()
{
  delete ledWindow;
  delete button;
}
