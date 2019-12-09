#include <graphics/renderer.h>
#include <graphics/vector3.h>
#include <cmath> 

typedef Vector3<float> Vector3f;

Renderer::Renderer()
    : scene(), _width(0), _height(0), _fov(90) {}

Renderer::Renderer(int width, int height, std::vector<Shape3*>& scene)
    : scene(scene), _width(width), _height(height), _fov(90) {
}


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

Vector3f Renderer::getPrimaryRay(int rasterX, int rasterY) const{
    /*
        Gets the primary ray direction at the origin (0,0,0), where the camera is facing the -Z axis (0,0,-1)
    */
    double ndcX = (rasterX + .5) / this->_width;  // rasterX is actually the top left corner of the pixel. We add .5 to get its center.
    double ndcY = (rasterY + .5) / this->_height;
    double aspectRatio = this->_width / this->height; // What if height > width??
    double screenX = (2 * ndcX - 1) * aspectRatio * tan(this->_fov / 2);
    double screenY = 1 - 2 * ndcY * tan(this->_fov / 2);
    return Vector3f(screenX, screenY, -1); 
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
