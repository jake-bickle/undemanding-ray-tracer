#include "ppm.h"
#include <iostream>
#include <fstream>

PPM::PPM(int width, int height)
    : _width(width), _height(height){
    _pixels = new Vector3f[width * height];  // Vectors are colored black by default
}

PPM::~PPM(){
    delete[] _pixels;
}

void PPM::colorPixel(int rasterX, int rasterY, const Vector3f& color){
    _pixels[rasterX + _width * rasterY] = color;
}

void PPM::saveToFile(const char* fileLocation) const{

}