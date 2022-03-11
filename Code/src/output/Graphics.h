#pragma once
#include "DotMatrix.h"

class Graphics
{
private:
    inline static DotMatrix* s_dotMatrix;

public:
    Graphics()
    {
        s_dotMatrix = new DotMatrix();
        s_dotMatrix->setDisplayBrightness(1);
    }

    ~Graphics()
    {
        delete s_dotMatrix;
    }

    static DotMatrix* GetDotMatrix() { return s_dotMatrix; }
};