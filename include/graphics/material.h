#pragma once
#include "vector3.h"

typedef Vector3<float> Vector3f;

struct Material{
    Vector3f color,
             lightIntensity,
             lightColor;
    float transparency, 
          reflectivity;

    Material();
    Material(const Material& copy);
};
