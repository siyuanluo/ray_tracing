//
//  ray.h
//  chap4
//
//  Created by lsy on 02/02/2021.
//

#ifndef ray_h
#define ray_h
#include "vec3.h"

class ray {
    public:
        point3 orig;
        vec3 dir;
    public:
        ray(){};
        ray(const point3& origin, const vec3& direct) : orig(origin), dir(direct){};
        
    point3 origin() const {return orig;}
    vec3 direct() const {return dir;}
    
    point3 at(double t) const{
        return orig + dir*t;
    }
    //P(t) = A + B * t
    
};

#endif /* ray_h */
