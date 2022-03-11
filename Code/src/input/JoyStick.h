#pragma once
#include <Arduino.h>
#include "../utils/Math.h"
#include "InputDevice.h"

#define JOYSTICK_NEUTRAL_POS    0
#define JOYSTICK_UP_POS         1
#define JOYSTICK_DOWN_POS       2
#define JOYSTICK_LEFT_POS       3
#define JOYSTICK_RIGHT_POS      4

class JoyStick : public InputDevice
{
private:
    unsigned m_pinX;
    unsigned m_pinY;
    unsigned m_buttonPin;

    Vector2 m_axis;

    bool m_wasPressed;

    int m_lastPos;

public:
    JoyStick(InputDeviceType input, unsigned pinX, unsigned pinY, unsigned buttonPin): InputDevice(input), m_pinX(pinX), m_pinY(pinY), m_buttonPin(buttonPin)
    {
        pinMode(m_pinX, INPUT);
        pinMode(m_pinY, INPUT);
        pinMode(m_buttonPin, INPUT_PULLUP);
    }

    Event updateEvents() override
    {
        Event event;
        event.device = m_eventInput;

        int rawX = analogRead(m_pinX);
        float x = map(rawX, 0, 1023, -100, 100);

        int rawY = analogRead(m_pinY);
        float y = map(rawY, 0, 1023, 100, -100);

        bool isPressed = !digitalRead(m_buttonPin);

        m_axis = { x, y };

        // Button check
        if (m_wasPressed)
        {
            if (isPressed == LOW)
            {
                m_wasPressed = false;
                event.type = EventType::JoyStickReleased;
                return event;
            }
        } else
        {
            if (isPressed == HIGH)
            {
                m_wasPressed = true;
                event.type = EventType::JoyStickPressed;
                return event;
            }
        }
        
        if (x > 75) // Right
        {
            if (m_lastPos != JOYSTICK_RIGHT_POS)
            {
                m_lastPos = JOYSTICK_RIGHT_POS;
                event.type = EventType::JoyStickRight;
                return event;
            }
        } else if (x < -75) // Left
        {
            if (m_lastPos != JOYSTICK_LEFT_POS)
            {
                m_lastPos = JOYSTICK_LEFT_POS;
                event.type = EventType::JoyStickLeft;
                return event;
            }
        } else if (y > 75) // Up
        {
            if (m_lastPos != JOYSTICK_UP_POS)
            {
                m_lastPos = JOYSTICK_UP_POS;
                event.type = EventType::JoyStickUp;
                return event;
            }
        } else if (y < -75) // Down
        {
            if (m_lastPos != JOYSTICK_DOWN_POS)
            {
                m_lastPos = JOYSTICK_DOWN_POS;
                event.type = EventType::JoyStickDown;
                return event;
            }
        } else // Neutral
        {
            m_lastPos = JOYSTICK_NEUTRAL_POS;
        }

        event.type = EventType::None;
        return event;
    }

    inline Vector2 GetAxis()
    {
        return m_axis;
    }

    inline bool isPressed()
    {
        return m_wasPressed;
    }
};