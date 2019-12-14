#pragma once
#include <vector>
#include <memory>
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
    std::vector<std::shared_ptr<Shape3>> scene;  // TODO Make Shape3* a std::unique_pointer
    int _width,
        _height,
        _fov;

public:
    Renderer();
    Renderer(int width, int height);
    Renderer& width(int w);
    Renderer& height(int h);
    Renderer& fov(int fov);
    void addShapeToScene(std::shared_ptr<Shape3>& shape);
    void addShapeToScene(std::shared_ptr<Shape3> shape);
    void render(const char* imageLocation) const;
    Vector3f castRay(const Vector3f& origin, const Vector3f& primaryRayDirection) const;
    Vector3f getPrimaryRay(int i, int j) const;
    bool findNearestVisibleObject(const Vector3f& origin, const Vector3f& primaryRayDirection,
                                        Intersection& intersection) const;
};
