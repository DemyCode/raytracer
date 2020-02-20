//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_SPHERE_HH
#define RAYTRACER_SPHERE_HH

#include <scene/texture/uniformtexture.hh>

#include "object.hh"

class Sphere : public Object
{
public:
    Sphere(Vector3 center, double r, TextureMaterial *textureMaterial);
    Sphere(Sphere const &) = default;
    Sphere() = default;
    std::optional<Vector3> intersect(Ray ray) override;
    Vector3 normal(Vector3 point) override;
private:
    Vector3 center_;
    double r_;
};


#endif //RAYTRACER_SPHERE_HH
