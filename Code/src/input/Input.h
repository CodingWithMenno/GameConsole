#pragma once
//#include <array>
#include "../utils/Array.h"
//#include <vector>
#include "Button.h"
#include "../utils/Math.h"

#define MAX_EVENT_LISTENERS 10

class Input
{
private:
    //static InputDevice** s_inputDevices;
    static Array<InputDevice*, INPUT_DEVICES_AMOUNT> s_inputDevices;

    //static std::vector<EventListener*> s_listeners;
    static Array<EventListener*, MAX_EVENT_LISTENERS> s_listeners;
    // static EventListener* s_listeners[MAX_EVENT_LISTENERS];
    // static int s_listenerCount;

public:
    Input();
    ~Input();

    void registerInput(InputDevice* device);

    void update();

    // Public functions
    static bool IsButtonPressed(InputDeviceType type);

    // static Vector2 GetJoyStickAxis(InputDeviceType type);

    static void AddListener(EventListener* listener);
    static void RemoveListener(EventListener* listener);
};