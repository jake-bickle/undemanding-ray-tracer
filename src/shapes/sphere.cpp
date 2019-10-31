#include <graphics/shapes/sphere.h>

Sphere::Sphere()
    : Shape3(), center(0,0,0), radius(1) {}

Sphere::Sphere(const Vector3f& center, float radius, const Material& material)
    : Shape3(material), center(center), radius(radius) {}

bool Sphere::findIntersections(const Vector3f& rayOrigin, const Vector3f& rayDirection, 
                               Vector3f& intersect1, Vector3f& intersect2) const{
    /*
        Finds the points in front of the ray that intersects the Sphere.
        Returns true if there is at least one intersection.
        The distance from the origin to intersect1 is always <= the distance from the origin to intersect2

        For more information on how this is done, refer to 
        https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
    */
    float t0, t1 = 0;
    Vector3f L = rayOrigin - this->center;
    float a = 1;
    float b = 2 * rayDirection.dot(L); 
    float c = L.dot(L);
    if (!solveQuadratic(a, b, c, t0, t1)) return false;

    if (t0 > t1)
        std::swap(t0, t1);
    if (t0 < 0){
        t0 = t1;
        if (t0 < 0)
            return false;
    }

    intersect1 = rayOrigin + rayDirection * t0;
    intersect2 = rayOrigin + rayDirection * t1;
    return true;
}