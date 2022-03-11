#pragma once

#define INPUT_DEVICES_AMOUNT 3
enum InputDeviceType
{
    ActionButton,
    HomeButton,

    LeftJoyStick
};

enum class EventType
{
    None,

    ButtonPressed,
    ButtonReleased,

    JoyStickPressed,
    JoyStickReleased,
    JoyStickLeft,
    JoyStickRight,
    JoyStickUp,
    JoyStickDown
};

struct Event
{
    InputDeviceType device;
    EventType type;
};

class EventListener
{
public:
    virtual ~EventListener() = default;

    virtual void onEvent(const Event& event) = 0;
};