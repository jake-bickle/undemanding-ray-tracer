#pragma once
#include "vector3.h"

typedef Vector3<float> Vector3f;

struct Material{
    Vector3f color,
             lightColor;
    float transparency, 
          reflectivity,
          lightIntensity;

    Material();
    Material(const Material& copy);
};
