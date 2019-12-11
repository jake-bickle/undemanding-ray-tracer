#include <ppm.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <string>

namespace fs = std::__fs::filesystem;

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
    fs::path path = getSanitizedPath(fileLocation);
    std::ofstream file;
    file.open(path);
    file << "P3" << std::endl
         << "#" << path.filename() << std::endl
         << _width << _height << std::endl
         << "255";
    for (int i = 0; i < _width * _height; ++i){
        Vector3f currentRGB = _pixels[i];
        file << currentRGB.x << ' ' << currentRGB.y << ' ' << currentRGB.z << ' ';
        // No line can have more than 70 characters
        // Since each RGB value written may have at most 12 characters, we can only write 5 values per line
        if (i % 5 == 0){
            file << std::endl;
        }
    }
    file.close();
}

fs::path PPM::getSanitizedPath(const char* fileLocation) const{
    fs::path path(fileLocation); 
    addExt(path);
    makeUniqueName(path);
    return path;
}

fs::path& PPM::addExt(fs::path& path) const{
    if (path.extension() != ".ppm"){
        std::ostringstream newName;
        newName << path.filename().string() << ".ppm";
        path.replace_filename(newName.str());
    }
    return path;
}

fs::path& PPM::makeUniqueName(fs::path& path) const{
    auto stem = path.stem().string();
    auto ext = path.extension();
    for (int i = 1; fs::exists(path); ++i){
        std::ostringstream newName;
        newName << stem << '(' << i << ')' << ext;
        path.replace_filename(newName.str());
    }
    return path;
}