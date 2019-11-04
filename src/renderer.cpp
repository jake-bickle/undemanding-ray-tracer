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
    float closestObjectDistance = INFINITY;
    const Shape3* closestObject = NULL;
    for (auto object : scene){
        Vector3f intersection;
        if (object->findNearestIntersection(origin, primaryRayDirection, intersection)){
            float distance = intersection.magnitude();  // TODO This may be slow. Perhaps the distance could be given by findNearestIntersection instead
            if (distance < closestObjectDistance)
                closestObjectDistance = distance;
                closestObject = object;
        }
    }
    return closestObject;
}
