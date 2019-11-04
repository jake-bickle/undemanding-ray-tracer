#pragma once
#include "shape3.h"
#include "graphics/vector3.h"

typedef Vector3<float> Vector3f;

class Sphere : public Shape3{
public:
    Vector3f center;
    float radius;

    Sphere();
    Sphere(const Vector3f& center, float radius, const Material& material);
    bool findNearestIntersection(const Vector3f& rayOrigin, const Vector3f& rayDirection, Vector3f& intersect) const;
};