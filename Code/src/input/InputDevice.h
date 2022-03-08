#pragma once
#include "Event.h"

class InputDevice
{
protected:
    InputDeviceType m_eventInput;

public:
    InputDevice(InputDeviceType input): m_eventInput(input) {}
    virtual ~InputDevice() = default;

    virtual Event updateEvents() = 0;

    InputDeviceType getInputDeviceType() { return m_eventInput; }
};