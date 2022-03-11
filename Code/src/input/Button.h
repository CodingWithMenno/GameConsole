#pragma once
#include <Arduino.h>
#include "InputDevice.h"

class Button : public InputDevice
{
private:
    unsigned m_pin;

    bool m_wasPressed;

public:
    Button(InputDeviceType input, unsigned pin, bool useBuiltInResistor = false): InputDevice(input)
    {
        m_pin = pin;
        useBuiltInResistor ? pinMode(m_pin, INPUT_PULLUP) : pinMode(m_pin, INPUT);
    }

    Event updateEvents() override
    {
        Event event;
        event.device = m_eventInput;

        bool state = !digitalRead(m_pin);

        if (m_wasPressed)
        {
            if (state == HIGH)
            {
                event.type = EventType::None;
            } else
            {
                m_wasPressed = false;
                event.type = EventType::ButtonReleased;
            } 
        } else
        {
            if (state == HIGH)
            {
                m_wasPressed = true;
                event.type = EventType::ButtonPressed;
            } else
            {
                event.type = EventType::None;
            } 
        }

        return event;
    }

    inline bool isPressed()
    {
        return m_wasPressed;
    }
};