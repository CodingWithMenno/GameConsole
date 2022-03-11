#include "src/Log.h"

#include "src/SceneManager.h"
#include "src/LibraryScene.h"

#include "src/input/Input.h"
#include "src/output/Graphics.h"
#include "src/input/JoyStick.h"

#define SERIAL_BAUD     9600

void setup() 
{
  Log::Init(SERIAL_BAUD);

  Graphics* graphics = new Graphics();
  startupSequence();

  Input* inputSystem = new Input();
  inputSystem->registerInput(new JoyStick(InputDeviceType::LeftJoyStick, A0, A1, 2));

  SceneManager* sceneManager = new SceneManager(new LibraryScene());

  while (sceneManager->isRunning())
  {
    sceneManager->update();
    inputSystem->update();
  }

  delete sceneManager;
  delete inputSystem;
  delete graphics;
}

void startupSequence()
{
  DotMatrix* matrix = Graphics::GetDotMatrix();

  for (int x = 0; x < NUM_DISPLAYS_X * PIXELS_PER_DISPLAY_X; x++)
  {
    matrix->setPixel(x, 7, true);
    matrix->setPixel(x, 8, true);
    delay(20);
  }
}

void loop()
{
  // Empty
}