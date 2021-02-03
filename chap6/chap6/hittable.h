//
//  hittable.h
//  chap6
//
//  Created by lsy on 03/02/2021.
//

#ifndef hittable_h
#define hittable_h

#include "ray.h"

struct hit_record(){
    point3 p;
    vec3 normal;
    double t;
};

class hittable
{
    public:
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record& rec) const = 0;
};


#endif /* hittable_h */
