#pragma once
#include "graphics/vector3.h"
#include <filesystem>

namespace fs = std::__fs::filesystem;

typedef Vector3<float> Vector3f;

class PPM{
public:
    PPM(int width, int height);
    ~PPM();
    void colorPixel(int rasterX, int rasterY, const Vector3f& color);
    void saveToFile(const char* fileLocation) const;

private:
    int _width;
    int _height;
    Vector3f* _pixels;

    fs::path getSanitizedPath(const char* fileLocation) const;
    fs::path& makeUniqueName(fs::path& path) const;
    fs::path& addExt(fs::path& path) const;
};