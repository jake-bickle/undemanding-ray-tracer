#pragma once
#include "graphics/vector3.h"

typedef Vector3<float> Vector3f;

class PPM{
public:
    PPM(int width, int height);
    ~PPM();
    void colorPixel(int rasterX, int rasterY, const Vector3f& color);
    void saveToFile(const char* fileLocation) const;

private:
    int _width;
    int _height;
    Vector3f* _pixels;
};