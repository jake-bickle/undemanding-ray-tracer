#include <graphics/shapes/shape3.h>
#include <cmath>

Shape3::Shape3() {}

Shape3::Shape3(const Shape3& copy){
    *this = copy;
}

Shape3::Shape3(const Material& material)
    : material(material) {}

Shape3& Shape3::setMaterial(const Material& material){
    this->material = material;
    return *this;
}

const Material& Shape3::getMaterial() const{
    return material;
}

Shape3& Shape3::operator= (const Shape3& rhs){
    this->material = rhs.material;
    return *this;
}

Intersection::Intersection()
    : coordinates(), shape(NULL), distance(INFINITY) {};