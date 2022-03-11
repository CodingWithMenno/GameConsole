#pragma once
#include "Scene.h"
#include "input/Input.h"
#include "output/Graphics.h"
#include "output/DotMatrix.h"

class LibraryScene : public Scene, EventListener
{
private:
    Vector2 pos;

public:
    LibraryScene()
    {
        Input::AddListener(this);

        pos = {0, 0};
    }

    ~LibraryScene()
    {
        Input::RemoveListener(this);
    }

    void update(float delta) override
    {
        delay(50);
    }

    void draw() override
    {
        DotMatrix* matrix = Graphics::GetDotMatrix();
        
        matrix->clear();
        matrix->setPixel(pos.x, pos.y, true);
    }

    void onEvent(const Event& event) override
    {
        switch (event.type)
        {
            case EventType::JoyStickUp: pos.y++; break;
            case EventType::JoyStickDown: pos.y--; break;
            case EventType::JoyStickLeft: pos.x--; break;
            case EventType::JoyStickRight: pos.x++; break;
        }
    }
};