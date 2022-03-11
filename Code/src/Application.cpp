#include "Application.h"
#include "Log.h"

Application::Application(Scene* scene)
{
    m_isRunning = true;
    s_activeScene = scene;
}

Application::~Application()
{
    delete s_activeScene;
}

void Application::update()
{
    static unsigned long timeOld = 0;
    unsigned long frameStartTime = millis();
    unsigned long deltaTimeMillis = frameStartTime - timeOld;
    float deltaTime = deltaTimeMillis / 1000.0;
    timeOld = frameStartTime;

    s_activeScene->update(deltaTime);
    s_activeScene->draw();
}

void Application::ChangeScene(Scene* scene)
{
    delete s_activeScene;
    s_activeScene = scene;
}