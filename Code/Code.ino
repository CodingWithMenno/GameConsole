#include "src/Log.h"
#include "src/Application.h"

#include "src/output/LedWindow.h"
// #include "Button.h"

#define SERIAL_BAUD     9600

// Led Window settings
#define NUM_DISPLAYS_X  4
#define NUM_DISPLAYS_Y  1
#define DIN_PIN         11
#define CLK_PIN         12
#define CS_PIN          10

LedWindow* ledWindow;

// Button* button;

void setup() 
{
  Log::Init(SERIAL_BAUD);

  // Initialiseer inputs & outputs (de poorten)

  ledWindow = new LedWindow(DIN_PIN, CLK_PIN, CS_PIN, NUM_DISPLAYS_X, NUM_DISPLAYS_Y);
  ledWindow->setDisplayBrightness(4);
  ledWindow->clear();
  ledWindow->setPixel(0, 0, 1, true);

  Application* app = new Application();

  while (app->isRunning())
  {
    app->update();

    // Update de inputs
  }

  delete app;

  // Verwijder de inputs

  // button = new Button(2);
}

void loop() {}
// {
//   ledWindow->clear();

//   if (button->isPressed())
//   {
//     ledWindow->setPixel(7, 4, 0, true);
//   }
// }

// void shutdown()
// {
//   delete ledWindow;
//   delete button;
// }
