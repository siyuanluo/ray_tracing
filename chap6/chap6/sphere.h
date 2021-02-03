//
//  sphere.h
//  chap6
//
//  Created by lsy on 03/02/2021.
//

#ifndef sphere_h
#define sphere_h

#include "vec3.h"
#include "hittable.h"

class sphere : public hittable
{
    public:
        sphere();
        sphere(point3 cen, double r) : center(r), radius(r){};
    
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
    
    public:
        point3 center;
        double radius;
};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const{
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;

    auto discriminant = half_b * half_b - a * c;
    if(discriminant < 0)
        return false;
    auto sqrtd = sqrt(discriminant);
    
    auto root = (-half_b -sqrtd) / a;
    if(root < t_min || root > t_max){
        root = (-half_b + sqrtd) / a;
        if(root < t_min || root > t_max){
            return false;
        }
    }
    
    rec.t = root;
    rec.p = r.at(rec.t);
    rec.normal = (rec.p - center) / radius;
    
}
#endif /* sphere_h */
