#include <graphics/shapes/shape3.h>
#include <cmath>

Shape3::Shape3() {}

Shape3::Shape3(const Shape3& copy){
    *this = copy;
}

Shape3::Shape3(const Vector3f& origin, const Material& material)
    : origin(origin), material(material) {}

Shape3& Shape3::operator= (const Shape3& rhs){
    this->origin = rhs.origin;
    this->material = rhs.material;
    return *this;
}

Intersection::Intersection()
    : coordinates(), shape(NULL), distance(INFINITY) {};