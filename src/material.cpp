#include <graphics/material.h>

Material::Material()
    : color(246, 199, 255), lightIntensity(0), lightColor(0), transparency(0), reflectivity(0) {}

Material::Material(const Material& copy)
    : color(copy.color), lightIntensity(copy.lightIntensity), lightColor(copy.lightColor),
      transparency(copy.transparency), reflectivity(copy.reflectivity) {}