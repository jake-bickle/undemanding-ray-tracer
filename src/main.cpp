#include <iostream>
#include <vector>
#include <graphics/shapes/sphere.h>
#include <graphics/material.h>

typedef Vector3<float> Vec3f;

int main(){
    Material green;
    Material lightSource;
    green.color = Vector3f(69, 252, 3);
    lightSource.lightIntensity = 1;
    std::vector<Shape3*> scene;
    scene.push_back(new Sphere(Vector3f(10,0,10), 3, green));
    scene.push_back(new Sphere(Vector3f(8,10,5), 3, green));
    scene.push_back(new Sphere(Vector3f(0,20,0), 3, lightSource));
    return 0;
}