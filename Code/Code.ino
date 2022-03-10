#include "src/Log.h"
#include "src/Application.h"

#include "src/output/DotMatrix.h"

#define SERIAL_BAUD     9600

DotMatrix* ledWindow;

void setup() 
{
  Log::Init(SERIAL_BAUD);

  // Initialiseer inputs & outputs (de poorten)

  ledWindow = new DotMatrix();
  ledWindow->setDisplayBrightness(1);
  ledWindow->clear();

  // Application* app = new Application();

  // while (app->isRunning())
  // {
  //   app->update();

  //   // Update de inputs
  // }

  // delete app;

  // Verwijder de inputs
}

void loop()
{
  for (int y = 0; y < NUM_DISPLAYS_Y * PIXELS_PER_DISPLAY_Y; y++)
  {
    for (int x = 0; x < NUM_DISPLAYS_X * PIXELS_PER_DISPLAY_X; x++)
    {
      ledWindow->setPixel(x, y, true);
      delay(50);
    }
  }

  ledWindow->clear();
}