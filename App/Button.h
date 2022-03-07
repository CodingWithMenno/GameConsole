#pragma once

class Button
{
private:
    unsigned m_pin;

public:
    Button(unsigned pin)
    {
        m_pin = pin;
        pinMode(m_pin, INPUT);
    }

    bool isPressed()
    {
        int state = digitalRead(m_pin);

        if (state == HIGH)
        {
            return true;
        } else
        {
            return false;
        }
    }
};