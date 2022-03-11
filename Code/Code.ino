#include "src/Log.h"
#include "src/Application.h"

#include "src/input/Input.h"
#include "src/output/DotMatrix.h"
#include "src/input/JoyStick.h"

#define SERIAL_BAUD     9600

Input* input;

// DotMatrix* ledWindow;
// JoyStick* joyStick;

class Test : public EventListener
{
public:
  void onEvent(const Event& event) override
  {
    if (event.type == EventType::JoyStickPressed)
    {
      // LOG_INFO("JoyStick Pressed")
      Serial.println("Test");
    }
  }
};

Test* test;

void setup() 
{
  Log::Init(SERIAL_BAUD);

  // Initialiseer inputs & outputs (de poorten)

  // ledWindow = new DotMatrix();
  // ledWindow->setDisplayBrightness(1);
  // ledWindow->clear();

  LOG_INFO("Hier")

  input = new Input();
  input->registerInput(new JoyStick(InputDeviceType::LeftJoyStick, A0, A1, 2));

  test = new Test();
  Input::AddListener(test);

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
  input->update();

  // Event e = joyStick->updateEvents();
  
  // switch (e.type)
  // {
  // case EventType::JoyStickPressed: LOG_INFO("JoyStickPressed") break;
  // case EventType::JoyStickReleased: LOG_INFO("JoyStickReleased") break;
  // case EventType::JoyStickDown: LOG_INFO("JoyStickDown") break;
  // case EventType::JoyStickLeft: LOG_INFO("JoyStickLeft") break;
  // case EventType::JoyStickRight: LOG_INFO("JoyStickRight") break;
  // case EventType::JoyStickUp: LOG_INFO("JoyStickUp") break;
  // }

  // delay(100);
}