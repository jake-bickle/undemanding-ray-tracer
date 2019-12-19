#include <iostream>
#include <vector>
#include <memory>
#include <graphics/shapes/sphere.h>
#include <graphics/material.h>
#include <graphics/renderer.h>

#include <ppm.h>

typedef Vector3<float> Vec3f;

int main(){
    const char* filename = "/Users/jacobbickle/dev/cpp/graphics/my_first_render";
    std::vector<std::unique_ptr<Shape3>> scene;

    Material green;
    Material red;
    Material lightSource;
    green.color = Vector3f(69, 252, 3);
    red.color = Vector3f(245, 90, 60);
    lightSource.lightIntensity = .5;
    lightSource.lightColor = Vector3f(255,255,225);
    Renderer r(800,600);
    r.addShapeToScene(std::shared_ptr<Shape3>(new Sphere(Vector3f(-2,0,-10), 1, green)));
    r.addShapeToScene(std::shared_ptr<Shape3>(new Sphere(Vector3f(2,5,-10), 1.5, red)));
    r.addShapeToScene(std::shared_ptr<Shape3>(new Sphere(Vector3f(0,-5,-5), 1, lightSource)));
    r.addShapeToScene(std::shared_ptr<Shape3>(new Sphere(Vector3f(0,10,-15), 1, lightSource)));
    r.addShapeToScene(std::shared_ptr<Shape3>(new Sphere(Vector3f(-7,5,-5), 1, lightSource)));
    r.addShapeToScene(std::shared_ptr<Shape3>(new Sphere(Vector3f(7,5,-5), 1, lightSource)));

    r.render(filename);

    return 0;
}