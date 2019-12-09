#pragma once
#include <vector>
#include <graphics/shapes/shape3.h>

typedef Vector3<float> Vector3f;

class Renderer{
/*
    The Renderer has a scene of Shapes that can be rendered to an image of arbitrary size.
    Some limitations that I plan to get around are the following:
    - The "camera" is positioned only at the origin (0,0,0)
    - The "camera" is only looking in the -Z axis direction (0,0,-1)

    Additionally, I don't think the Renderer should hold the data for a scene. That may be a future refactor.
*/
    std::vector<const Shape3*> scene;
    int _width,
        _height,
        _fov;

public:
    Renderer();
    Renderer(int width, int height);
    Renderer& width(int w);
    Renderer& height(int h);
    Renderer& fov(int fov);
    void addShapeToScene(const Shape3* shape);
    void render(const char* image_location) const;
    Vector3f getPrimaryRay(int i, int j) const;
    const Shape3* findVisibleObject(const Vector3f& primaryRayDirection) const;
};
