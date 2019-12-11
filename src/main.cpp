#include <iostream>
#include <vector>
#include <graphics/shapes/sphere.h>
#include <graphics/material.h>
#include <graphics/renderer.h>

#include <ppm.h>

typedef Vector3<float> Vec3f;

int main(){
    const char* filename = "/Users/jacobbickle/dev/cpp/graphics/my_first_render";

    Material green;
    Material red;
    Material lightSource;
    green.color = Vector3f(69, 252, 3);
    red.color = Vector3f(245, 90, 60);
    lightSource.lightIntensity = 1;
    Renderer r(800,600);
    r.addShapeToScene(new Sphere(Vector3f(0,0,-10), 1, green));
    r.addShapeToScene(new Sphere(Vector3f(1,1,-5), 1, red));
    r.addShapeToScene(new Sphere(Vector3f(-1,-1,-5), 1, lightSource));

    r.render(filename);

    return 0;
}