#include "SceneManager.h"
#include "Log.h"

SceneManager::SceneManager(Scene* scene)
{
    m_isRunning = true;
    s_activeScene = scene;
}

SceneManager::~SceneManager()
{
    delete s_activeScene;
}

void SceneManager::update()
{
    static unsigned long timeOld = 0;
    unsigned long frameStartTime = millis();
    unsigned long deltaTimeMillis = frameStartTime - timeOld;
    float deltaTime = deltaTimeMillis / 1000.0;
    timeOld = frameStartTime;

    s_activeScene->update(deltaTime);
    s_activeScene->draw();
}

void SceneManager::ChangeScene(Scene* scene)
{
    delete s_activeScene;
    s_activeScene = scene;
}