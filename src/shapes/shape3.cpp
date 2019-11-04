#include <graphics/shapes/shape3.h>
#include <cmath>

Shape3::Shape3() {}

Shape3::Shape3(const Material& material)
    : material(material) {}

Shape3& Shape3::setMaterial(const Material& material){
    this->material = material;
    return *this;
}

bool solveQuadratic(const float& a, const float& b, const float& c, float& x1, float& x2){
    /*
        Finds the x values where ax^2 + bx + c = 0
        Returns true if there is at least one solution. x1 and x2 will be the same if there is only one solution.
        x1 will always be <= x2 if the function returns true
    */
    float discriminate = (b * b) - (4 * a * c);
    if (discriminate < 0)
        return false;
    else if (discriminate == 0){
        if (a == 0) return false;
        x1 = -0.5 * b / a;
        x2 = x1;
    }
    else{
        if (a == 0) return false;
        x1 = (-b + sqrt(discriminate)) / 2 * a;
        x2 = (-b - sqrt(discriminate)) / 2 * a;
        if (x1 > x2)
            std::swap(x1, x2);
    }
    return true;
        
}
