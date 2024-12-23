#pragma once

#include <cstdint>

#include "interval.h"
#include "vec3.h"

using color = vec3;

void write_color(uint8_t* pixels, int& index, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate the [0,1] component values to the byte range [0,255].
    static const interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    // Write out the pixel color components.

    pixels[index++] = rbyte; 
    pixels[index++] = gbyte; 
    pixels[index++] = bbyte; 
}