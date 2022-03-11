#pragma once
#include "Scene.h"

class Application
{
private:
    bool m_isRunning;

    inline static Scene* s_activeScene;

public:
    Application(Scene* scene);
    ~Application();

    void update();

    bool isRunning() { return m_isRunning; }

    // Public functions
    static void ChangeScene(Scene* scene);
};