#include <graphics/shapes/shape3.h>
#include <cmath>

Shape3::Shape3() {}

Shape3::Shape3(const Material& material)
    : material(material) {}

Shape3& Shape3::setMaterial(const Material& material){
    this->material = material;
    return *this;
}


Intersection::Intersection()
    : coordinates(), shape(NULL), distance(INFINITY) {};