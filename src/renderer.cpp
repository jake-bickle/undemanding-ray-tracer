#include <graphics/renderer.h>
#include <graphics/vector3.h>
#include <cmath> // INFINITY

typedef Vector3<float> Vector3f;

Renderer::Renderer()
    : scene(), _width(0), _height(0), _fov(0) {}

void Renderer::addShapeToScene(const Shape3* shape){
    scene.push_back(shape);
}

void Renderer::render(const char* image_location) const{
    for (int j = 0; j < _height; ++j){
        for (int i = 0; i < _width; ++i){
            Vector3f primaryRayDir = getPrimaryRay(i, j);
            const Shape3* visibleObject = findVisibleObject(primaryRayDir);
        }
    }
}

Vector3f Renderer::getPrimaryRay(int i, int j) const{

}

const Shape3* Renderer::findVisibleObject(const Vector3f& primaryRayDirection) const{
    Vector3f origin(0);
    Intersection currentIntersection;
    Intersection nearestIntersection;
    for (auto object : scene){
        if (object->findNearestIntersection(origin, primaryRayDirection, currentIntersection)){
            if (currentIntersection.distance < nearestIntersection.distance)
                nearestIntersection = currentIntersection;
        }
    }
    return nearestIntersection.shape;
}
