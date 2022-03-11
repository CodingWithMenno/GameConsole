#pragma once
#include "Button.h"
#include "JoyStick.h"
#include "../utils/Math.h"

#define MAX_EVENT_LISTENERS 10

class Input
{
private:
    static InputDevice* s_inputDevices[INPUT_DEVICES_AMOUNT];

    static EventListener* s_listeners[MAX_EVENT_LISTENERS];
    static int s_listenerCount;

public:
    Input() = default;
    ~Input();

    void registerInput(InputDevice* device);

    void update();

    // Public functions
    static bool IsButtonPressed(InputDeviceType type);

    static Vector2 GetJoyStickAxis(InputDeviceType type);

    static void AddListener(EventListener* listener);
    static void RemoveListener(EventListener* listener);
};