#include <graphics/shapes/sphere.h>
#include <cmath> 

Sphere::Sphere()
    : Shape3(), center(0,0,0), radius(1) {}

Sphere::Sphere(const Vector3f& center, float radius, const Material& material)
    : Shape3(material), center(center), radius(radius) {}

bool Sphere::findNearestIntersection(const Vector3f& rayOrigin, const Vector3f& rayDirection, Intersection& intersect) const{
    /*
        Finds the closest point of intersection with the Sphere in front of the ray.
        Returns true if an intersection exists

        rayDirection is assumed to be a normalized vector (a length of one unit). If it isn't, results will be innacurate. 

        For more information on how this is done, refer to 
        https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
    */
    float t0, t1 = 0;
    Vector3f L = rayOrigin - this->center;
    float a = 1;
    float b = 2 * rayDirection.dot(L); 
    float c = L.dot(L) - (this->radius * this->radius);
    if (!solveQuadratic(a, b, c, t0, t1)) 
        return false;

    if (t0 > t1)
        std::swap(t0, t1);
    if (t0 < 0){
        t0 = t1;
        if (t0 < 0)
            return false;
    }

    intersect.coordinates = rayOrigin + rayDirection * t0;
    intersect.shape = this;
    intersect.distance = t0;
    return true;
}

bool Sphere::solveQuadratic(const float& a, const float& b, const float& c, float& x1, float& x2){
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