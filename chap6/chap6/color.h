//
//  color.h
//  chap6
//
//  Created by lsy on 03/02/2021.
//
#ifndef color_h
#define color_h
#include "vec3.h"

#include <iostream>

using namespace std;

void write_color(ostream &out, color pixel_color){
    //[0,255]像素的表示
    out << static_cast<int>(255.99 * pixel_color.x()) << ' '
        << static_cast<int>(255.99 * pixel_color.y()) << ' '
        << static_cast<int>(255.99 * pixel_color.z()) << '\n';
}


#endif /* color_h */
