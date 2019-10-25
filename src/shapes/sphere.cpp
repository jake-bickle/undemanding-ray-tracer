#include <graphics/shapes/sphere.h>

Sphere::Sphere()
    : Shape3(), center(0,0,0), radius(1) {}

Sphere::Sphere(const Vector3f& center, float radius, const Material& material)
    : Shape3(material), center(center), radius(radius) {}

bool Sphere::intersects(const Vector3f& rayOrigin, const Vector3f& rayDirection) const{

}