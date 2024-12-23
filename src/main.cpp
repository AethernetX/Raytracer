#include <iostream>
#include <fstream>
#include <sstream>

#include "rtweekend.h"

#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

#include "camera.h"

int main() {
    // World
    hittable_list world;

    world.add(std::make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(std::make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.width  = 400;
    cam.samples_per_pixel = 100;

    cam.render(world);

    return 0;
}