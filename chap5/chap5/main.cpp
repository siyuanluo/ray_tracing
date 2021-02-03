//
//  main.cpp
//  chap5
//
//  Created by lsy on 03/02/2021.
//
#include "vec3.h"
#include "ray.h"
#include "color.h"
#include <iostream>

using namespace std;

bool hit_sphere(const point3& center, double radius, const ray &r)
{
    vec3 oc = r.origin() - center;
    auto a = dot(r.direct() ,r.direct());
    auto b = 2.0 * dot(oc, r.direct());
    auto c = dot(oc, oc) - radius * radius;
    //(t^2)b^2 + 2t(A-C)b + (A-C)(A-C) - r^2 = 0
    auto discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}

color ray_color(const ray &r)
{
    if(hit_sphere(point3(0,0,-1), 0.5, r))
        return color(0.5,0,0); //chap5_2.ppm
    vec3 unit_direction = unit_vector(r.direct());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0-t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main(int argc, const char * argv[]) {
    //just copy from chap4
    //Image
    const auto aspect_ratio = 16/9;//屏幕比
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    //这样写易于调整
    
    //Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height; //视口大小
    auto focal_length = 1.0;
    
    auto origin = point3(0,0,0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0,0,focal_length); //
    //定义ray参数
    
    //Render
    cout << "P3\n" << image_width << ' ' << image_height << "\n256\n";
    
    for(int j = image_height - 1; j >= 0; j--){
        cerr << "Remaining: " << j << ' ' << flush;
        for(int i = 0 ; i < image_width; i++){
            auto u = double(i) / (image_width-1);
            auto v = double(j) / (image_height-1);
            
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(r);
            write_color(cout, pixel_color);
        }
    }
    cerr << "\nDone\n";
    return 0;
}
