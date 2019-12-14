#pragma once
#include "shape3.h"
#include "graphics/vector3.h"

typedef Vector3<float> Vector3f;

class Sphere : public Shape3{
public:
    Vector3f center;
    float radius;

    Sphere();
    Sphere(const Sphere& copy);
    Sphere(const Vector3f& center, float radius, const Material& material);
    ~Sphere() {};
    bool findNearestIntersection(const Vector3f& rayOrigin, const Vector3f& rayDirection, Intersection& intersect) const;
    Sphere& operator= (const Sphere& rhs);
private:
    static bool solveQuadratic(const float& a, const float& b, const float& c, float& x1, float& x2);
};