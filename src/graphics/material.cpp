#include <graphics/material.h>

Material::Material()
    : color(246, 199, 255), lightColor(0), transparency(0), reflectivity(0), lightIntensity(0) {}

Material::Material(const Material& copy)
    : color(copy.color), lightColor(copy.lightColor), transparency(copy.transparency), 
      reflectivity(copy.reflectivity), lightIntensity(copy.lightIntensity) {}