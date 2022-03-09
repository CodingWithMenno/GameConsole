// #include "Input.h"
// #include "../Log.h"

// Input::Input()
// {
//     // s_inputDevices = (InputDevice**) malloc(sizeof(InputDevice*) * INPUT_DEVICES_AMOUNT);
//     // if (s_inputDevices == nullptr)
//     // {
//     //     LOG_ERROR("Could not allocate memory for the input devices!")
//     // }

//     // s_listenerCount = 0;
// }

// Input::~Input()
// {
//     // for (int i = 0; i < INPUT_DEVICES_AMOUNT; i++)
//     // {
//     //     delete s_inputDevices[i];
//     // }
// }

// void Input::registerInput(InputDevice* device)
// {
//     int type = device->getInputDeviceType();

//     if (s_inputDevices[type] != nullptr)
//     {
//         LOG_ERROR("Cannot add input device type more then once, overwriting previous set device type: " + type)
//         delete s_inputDevices[type];
//     }

//     s_inputDevices[type] = device;
// }

// void Input::update()
// {
//     for (int i = 0; i < INPUT_DEVICES_AMOUNT; i++)
//     {
//         if (s_inputDevices[i] == nullptr)
//         {
//             continue;
//         }

//         const Event& event = s_inputDevices[i]->updateEvents();

//         if (event.type != EventType::None)
//         {
//             for (auto* listener : s_listeners)
//             {
//                 listener->onEvent(event);
//             }
//         }
//     }
// }

// bool Input::IsButtonPressed(InputDeviceType type)
// {
//     if (s_inputDevices[type] == nullptr)
//     {
//         LOG_ERROR("Input device type does not exist!")
//         return false;
//     }

//     Button* button = dynamic_cast<Button*>(s_inputDevices[type]);
//     if (button != nullptr)
//     {
//         return button->isPressed();
//     }
// }

// // Vector2 Input::GetJoyStickAxis(InputDeviceType type)
// // {
// //     if (s_inputDevices[type] == nullptr)
// //     {
// //         LOG_ERROR("Input device type does not exist!")
// //         return { 0, 0 };
// //     }

// //     // TODO
// //     return { 0, 0 };
// // }

// void Input::AddListener(EventListener* listener)
// {
//     //s_listeners.push_back(listener);

//     s_listeners[s_listenerCount] = listener;
//     s_listenerCount++;
// }

// void Input::RemoveListener(EventListener* listener)
// {


//     // auto iterator = std::find(s_listeners.begin(), s_listeners.end(), listener);

//     // if (iterator != s_listeners.end())
//     // {
//     //     s_listeners.erase(iterator);
//     // } else
//     // {
//     //     LOG_ERROR("Cannot remove non-existent listener")
//     // }
// }