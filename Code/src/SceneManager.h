#pragma once
#include "Scene.h"

class SceneManager
{
private:
    bool m_isRunning;

    inline static Scene* s_activeScene;

public:
    SceneManager(Scene* scene);
    ~SceneManager();

    void update();

    bool isRunning() { return m_isRunning; }

    // Public functions
    static void ChangeScene(Scene* scene);
};