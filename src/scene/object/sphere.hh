//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_SPHERE_HH
#define RAYTRACER_SPHERE_HH

#include "object.hh"

class Sphere : public Object
{
public:
    Sphere(Vector3 center, int r);
    Sphere(Sphere const &) = default;
    Sphere() = default;
    Vector3* intersect(Ray ray) override;
    bool normal(Vector3 point) override;
    bool getTexture(Vector3 point) override;
private:
    Vector3 center_;
    int r_;
};


#endif //RAYTRACER_SPHERE_HH
