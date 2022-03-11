#include "Input.h"
#include "../Log.h"

Input::~Input()
{
    for (int i = 0; i < INPUT_DEVICES_AMOUNT; i++)
    {
        delete s_inputDevices[i];
    }
}

void Input::registerInput(InputDevice* device)
{
    int type = device->getInputDeviceType();

    if (s_inputDevices[type] != nullptr)
    {
        LOG_ERROR("Cannot add input device type more then once, overwriting previous set device type: " + type)
        delete s_inputDevices[type];
    }

    s_inputDevices[type] = device;
}

void Input::update()
{
    for (int i = 0; i < INPUT_DEVICES_AMOUNT; i++)
    {
        if (s_inputDevices[i] == nullptr)
        {
            continue;
        }

        const Event& event = s_inputDevices[i]->updateEvents();

        if (event.type != EventType::None)
        {
            for (auto* listener : s_listeners)
            {
                listener->onEvent(event);
            }
        }
    }
}

bool Input::IsButtonPressed(InputDeviceType type)
{
    if (s_inputDevices[type] == nullptr)
    {
        LOG_ERROR("Input device type does not exist!")
        return false;
    }

    switch(s_inputDevices[type]->getInputDeviceType())
    {
        case InputDeviceType::ActionButton:
        case InputDeviceType::HomeButton:
        {
            Button* button = static_cast<Button*>(s_inputDevices[type]);
            return button->isPressed();
        }

        case InputDeviceType::LeftJoyStick:
        {
            JoyStick* joyStick = static_cast<JoyStick*>(s_inputDevices[type]);
            return joyStick->isPressed();
        }
    }

    LOG_ERROR("Given input device type is not a Button or JoyStick!")
    return false;
}

Vector2 Input::GetJoyStickAxis(InputDeviceType type)
{
    if (s_inputDevices[type] == nullptr)
    {
        LOG_ERROR("Input device type does not exist!")
        return { 0, 0 };
    }

    switch(s_inputDevices[type]->getInputDeviceType())
    {
        case InputDeviceType::LeftJoyStick:
        {
            JoyStick* joyStick = static_cast<JoyStick*>(s_inputDevices[type]);
            return joyStick->GetAxis();
        }
    }

    LOG_ERROR("Given input device type is not a JoyStick!")
    return { 0, 0 };   
}

void Input::AddListener(EventListener* listener)
{
    s_listeners[s_listenerCount] = listener;
    s_listenerCount++;
}

void Input::RemoveListener(EventListener* listener)
{
    int index = -1;
    for (int i = 0; i < s_listenerCount; i++)
    {
        if (s_listeners[i] == listener)
        {
            index = i;
        }
    }

    if (index == -1)
    {
        LOG_ERROR("Given listener cannot be removed, it is not registered yet!")
        return;
    }

    s_listenerCount--;
    s_listeners[index] = s_listeners[s_listenerCount];
}