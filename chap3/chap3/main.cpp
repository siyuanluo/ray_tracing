//
//  main.cpp
//  chap3
//
//  Created by lsy on 02/02/2021.
//
#include "color.h"
#include "vec3.h"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    //Image Part
    
    const int image_width = 256;
    const int image_height = 256;
    
    //Render Part
    cout << "P3\n" << image_width << ' ' << image_height << "\n256\n";
    for(int j = image_height - 1; j >= 0; j--){
        cerr << "Remaining: " << j << ' ' << flush;
        for(int i = 0 ; i < image_width; i++){
            color pixel_color(double(i)/(image_width - 1),
                              double(j)/(image_height - 1),
                              0.25);
            write_color(cout, pixel_color);
        }
    }
    cerr << "\nDone\n";
    
    return 0;
}
