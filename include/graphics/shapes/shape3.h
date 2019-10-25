#pragma once
#include "graphics/vector3.h"
#include "graphics/material.h"

typedef Vector3<float> Vector3f;

class Shape3{
    Material material;

public:
    Shape3();
    Shape3(const Material& material);
    virtual bool intersects(const Vector3f& rayOrigin, const Vector3f& rayDirection) const = 0;  // TODO Do I need t0 and t1?
                                                                                             // From line 95 at the link
            // https://www.scratchapixel.com/code.php?id=3&origin=/lessons/3d-basic-rendering/introduction-to-ray-tracing
};
