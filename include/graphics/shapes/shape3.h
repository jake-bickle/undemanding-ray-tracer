#pragma once
#include "graphics/vector3.h"
#include "graphics/material.h"

typedef Vector3<float> Vector3f;

class Shape3{
    Material material;

public:
    Shape3();
    Shape3(const Material& material);
    Shape3& setMaterial(const Material& material);
    virtual bool findIntersections(const Vector3f& rayOrigin, const Vector3f& rayDirection, Vector3f& intersect1,
                                   Vector3f& intersect2) const = 0;  
    bool findNearestIntersection(const Vector3f& rayOrigin, const Vector3f& rayOirection, Vector3f& intersect);
};

bool solveQuadratic(const float& a, const float& b, const float& c, float& x1, float& x2);
