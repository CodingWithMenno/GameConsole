#pragma once

class Application
{
private:
    bool m_isRunning;

public:
    Application();
    ~Application();

    void update();

    bool isRunning() { return m_isRunning; }
};