#pragma once
#include "Scene.h"
#include "output/Graphics.h"

class LibraryScene : public Scene
{
public:
    void update(float delta) override
    {

    }

    void draw() override
    {
        Graphics::GetDotMatrix()->clear();
    }
};