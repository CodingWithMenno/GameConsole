#pragma once

class Button
{
private:
    unsigned m_pin;

public:
    Button(unsigned pin, bool useBuiltInResistor = false)
    {
        m_pin = pin;
        useBuiltInResistor ? pinMode(m_pin, INPUT_PULLUP) : pinMode(m_pin, INPUT);
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