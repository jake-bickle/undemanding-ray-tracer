#include <graphics/renderer.h>
#include <graphics/vector3.h>
#include <ppm.h>
#include <cmath> 
#include <algorithm>

typedef Vector3<float> Vector3f;

Renderer::Renderer()
    : scene(), lightSources(), _width(0), _height(0), _fov(90), _rayDepth(10) {}

Renderer::Renderer(int width, int height)
    : scene(), lightSources(), _width(width), _height(height), _fov(90) {
}

void Renderer::addShapeToScene(pShape3 shape){
    scene.push_back(shape);
    if (shape->material.lightIntensity > 0)
        lightSources.push_back(shape);
}

void Renderer::render(const char* imageLocation) const{
    PPM img(_width, _height);
    const Vector3f origin(0,0,0);
    for (int j = 0; j < _height; ++j){
        for (int i = 0; i < _width; ++i){
            Vector3f primaryRayDir = getPrimaryRay(i, j);
            Vector3f color = castRay(origin, primaryRayDir);
            img.colorPixel(i, j, color);
        }
    }
    img.saveToFile(imageLocation);
}

Vector3f Renderer::getPrimaryRay(int rasterX, int rasterY) const{
    /*
        Gets the primary ray direction at the origin (0,0,0), where the camera is facing the -Z axis (0,0,-1)
    */
    double ndcX = (rasterX + .5) / this->_width;  // rasterX is actually the top left corner of the pixel. We add .5 to get its center.
    double ndcY = (rasterY + .5) / this->_height; // Add .5 for the same reason as started above
    double aspectRatio = this->_width / (float)this->_height;
    double screenX = (2 * ndcX - 1) * tan(this->_fov / 2) * aspectRatio;
    double screenY = (1 - 2 * ndcY) * tan(this->_fov / 2);
    return Vector3f(screenX, screenY, -1).normalize(); 
}

Vector3f Renderer::castRay(const Vector3f& origin, const Vector3f& primaryRayDirection) const{
    /*
        Casts ray in direction from the origin. Returns a Vector3f corresponding to the RGB value of the casted ray.
    */
    Vector3f color(0,0,0);
    Intersection i;
    if (findNearestVisibleObject(origin, primaryRayDirection, i)){
        color = i.shape->material.color;
        applyLightColoring(i, color);
    }
    return color.range(0, 255).floor();
}

bool Renderer::findNearestVisibleObject(const Vector3f& origin, const Vector3f& primaryRayDirection,
                                              Intersection& intersection) const{
    Intersection currentIntersection;
    Intersection nearestIntersection;
    for (auto& object : scene){
        if (object->findNearestIntersection(origin, primaryRayDirection, currentIntersection)){
            if (currentIntersection.distance < nearestIntersection.distance)
                nearestIntersection = currentIntersection;
        }
    }
    if (nearestIntersection.shape != NULL){
        intersection = nearestIntersection;
    }
    return nearestIntersection.shape != NULL;
}

Vector3f& Renderer::applyLightColoring(const Intersection& intersection, Vector3f& color) const{
    bool isShadowed = true;
    if (!lightSources.empty()){
        for (auto& lightSrc : lightSources){
            Vector3f origin = intersection.coordinates + intersection.normal * 1e-4;  // Is a point that's VERY close to the surface. Fixes "grainy" effect
            Vector3f direction = lightSrc->origin - intersection.coordinates;
            direction.normalize();
            if (hasDirectLineOfSight(origin, direction, lightSrc)){
                float dp = intersection.normal.dot(direction);
                if (std::max((float)0, dp) != 0){
                    color += (lightSrc->material.lightColor * dp);
                    color *= lightSrc->material.lightIntensity;
                    isShadowed = false;
                }
            }
        }
    }
    if (isShadowed)
        color *= 0;
    return color;
}

bool Renderer::hasDirectLineOfSight(const Vector3f& origin, const Vector3f& rayDirection, pShape3 shape) const{
    Intersection i;
    if (findNearestVisibleObject(origin, rayDirection, i)){
        return i.shape == shape.get();  // Intersection.shape is a raw pointer, so .get() is required
    }
    return false;
}
