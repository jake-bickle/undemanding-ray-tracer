#include <graphics/shapes/shape3.h>
#include <cmath>

Shape3::Shape3() {}

Shape3::Shape3(const Material& material)
    : material(material) {}

Shape3& Shape3::setMaterial(const Material& material){
    this->material = material;
    return *this;
}

bool Shape3::findNearestIntersection(const Vector3f& rayOrigin, const Vector3f& rayDirection, Vector3f& intersect){
    Vector3f intersect2;
    return findIntersections(rayOrigin, rayDirection, intersect, intersect2);
}


bool solveQuadratic(const float& a, const float& b, const float& c, float& x1, float& x2){
    /*
        Finds the x values where ax^2 + bx + c = 0
        Returns true if there is at least one solution. x1 and x2 will be the same if only one solution.
        x1 will always be <= x2 if the functionr returns true

        Uses slightly modified version of quadratic formula to eliminate the "loss of significance" effect. More info at
        https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
    */
    float discriminate = b * b - 4 * a * c;
    if (discriminate < 0)
        return false;
    else if (discriminate == 0){
        if (a == 0) return false;
        x1 = -0.5 * b / a;
        x2 = x1;
    }
    else{
        float q = (b > 0) ?
            -0.5 * b + sqrt(discriminate) :
            -0.5 * b - sqrt(discriminate);
        if (a == 0 || q == 0) return false;
        x1 = q / a;
        x2 = c / q;
        if (x2 > x1)
            std::swap(x1, x2);
    }
    return true;
        
}
