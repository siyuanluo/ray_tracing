//
//  main.cpp
//  chap6
//
//  Created by lsy on 03/02/2021.
//
#include "color.h"
#include "vec3.h"
#include "ray.h"
#include <iostream>

using namespace std;
/*double hit_sphere(const point3& center, double radius, const ray &r)
{
    vec3 oc = r.origin() - center;
    auto a = dot(r.direct() ,r.direct());
    auto b = 2.0 * dot(oc, r.direct());
    auto c = dot(oc, oc) - radius * radius;
    //(t^2)b^2 + 2t(A-C)b + (A-C)(A-C) - r^2 = 0
    auto discriminant = b * b - 4 * a * c;
    //对圆内进行shader区分颜色
    if(discriminant < 0){
        return -1.0;
    }
    else{
        return (-b - sqrt(discriminant)) / (2.0 * a); //返回左零点的解
    }
}
*/ //optimize the code
double hit_sphere(const point3 &center, double radius, const ray &r)
{
    vec3 oc = r.origin() - center;
    auto a = r.direct().length_squared();
    auto half_b = dot(oc, r.direct());
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = half_b * half_b - a * c;
    if(discriminant < 0){
        return -1.0;
    }
    else{
        return (-half_b - sqrt(discriminant)) / a;
    }
}

color ray_color(const ray &r)
{
    auto t = hit_sphere(point3(0,0,-1), 0.5, r);
    if(t > 0.0){
        vec3 N = unit_vector(r.at(t) - vec3(0,0,-1));
        return 0.7 * color(N.x()+1, N.y()+1, N.z()+1);
    }
    vec3 unit_direction = unit_vector(r.direct());
    t = 0.5 *(unit_direction.y() + 1.0);
    return (1.0-t) * color(1.0,1.0,1.0) + t * color(0.5, 0.7, 1.0);
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

