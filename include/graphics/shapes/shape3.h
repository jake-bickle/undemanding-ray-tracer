#pragma once
#include "graphics/vector3.h"
#include "graphics/material.h"

typedef Vector3<float> Vector3f;

struct Intersection;

class Shape3{
public:
    Vector3f origin;
    Material material;

    Shape3();
    Shape3(const Shape3& copy);
    Shape3(const Vector3f& origin, const Material& material);
    virtual ~Shape3(){};
    virtual bool findNearestIntersection(const Vector3f& rayOrigin, const Vector3f& rayDirection, Intersection& intersect) const = 0;

    Shape3& operator= (const Shape3& rhs);
};

struct Intersection{
    Intersection();
    Vector3f coordinates;
    Vector3f normal;
    const Shape3* shape;
    float distance;
};
