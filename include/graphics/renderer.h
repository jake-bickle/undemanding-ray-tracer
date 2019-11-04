#pragma once
#include <vector>
#include <graphics/shapes/shape3.h>

typedef Vector3<float> Vector3f;

class Renderer{
    std::vector<const Shape3*> scene;
    int _width,
        _height,
        _fov;

public:
    Renderer();
    Renderer(int width, int height, std::vector<Shape3*> scene);
    Renderer& width(int w);
    Renderer& height(int h);
    Renderer& fov(int fov);
    void addShapeToScene(const Shape3* shape);
    void render(const char* image_location) const;
    Vector3f getPrimaryRay(int i, int j) const;
    const Shape3* findVisibleObject(const Vector3f& primaryRayDirection) const;
};
