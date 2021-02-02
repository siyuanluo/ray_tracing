//
//  main.cpp
//  chap2
//
//  Created by lsy on 02/02/2021.
//

#include <iostream>
//Image
const int image_width = 256;
const int image_height = 256;

using namespace std;

int main() {
//Render
    cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for(int j = image_height - 1; j >= 0; j--){
    cerr << "\rScanlines remaining: " << j << ' ' << flush;
        for(int i = 0; i < image_width; i++)
        {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;
        
            int ir = static_cast<int>(r * 255.99);
            int ig = static_cast<int>(g * 255.99);
            int ib = static_cast<int>(b * 255.99);
        
            cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
        cerr << "\nDone.\n";
        return 0;
}
