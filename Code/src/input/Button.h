#pragma once
#include <Arduino.h>
#include "InputDevice.h"

class Button : InputDevice
{
private:
    unsigned m_pin;

    bool m_isPressed;
    bool m_firstTime;

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

        int state = digitalRead(m_pin);

        if (m_isPressed)
        {
            if (state == HIGH)
            {
                m_firstTime = false;
                event.type = EventType::None;
            } else
            {
                m_isPressed = false;
                m_firstTime = true;
                event.type = EventType::ButtonReleased;
            } 
        } else
        {
            if (state == HIGH)
            {
                m_isPressed = true;
                m_firstTime = true;
                event.type = EventType::ButtonPressed;
            } else
            {
                m_firstTime = false;
                event.type = EventType::None;
            } 
        }

        return event;
    }

    inline bool isPressed()
    {
        return m_isPressed;
    }
};