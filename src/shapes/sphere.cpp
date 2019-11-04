#include <graphics/shapes/sphere.h>

Sphere::Sphere()
    : Shape3(), center(0,0,0), radius(1) {}

Sphere::Sphere(const Vector3f& center, float radius, const Material& material)
    : Shape3(material), center(center), radius(radius) {}

bool Sphere::findNearestIntersection(const Vector3f& rayOrigin, const Vector3f& rayDirection, Vector3f& intersect) const{
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
    if (!solveQuadratic(a, b, c, t0, t1)) return false;

    if (t0 > t1)
        std::swap(t0, t1);
    if (t0 < 0){
        t0 = t1;
        if (t0 < 0)
            return false;
    }

    intersect = rayOrigin + rayDirection * t0;
    return true;
}