#pragma once

namespace Log
{
    #define LOG_INFO(x) { Serial.print("[INFO]"); Serial.println(x); }
    #define LOG_ERROR(x) { Serial.print("[ERROR]"); Serial.println(x); }

    inline void Init(int serialBaud)
    {
        Serial.begin(serialBaud);
    }
}