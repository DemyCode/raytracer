//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_OBJECT_HH
#define RAYTRACER_OBJECT_HH

#include <optional>

#include <scene/texture/texturematerial.hh>
#include <utils/vector3.hh>
#include <utils/ray.hh>

class Object {
public:
    virtual std::optional<Vector3> intersect(Ray ray) = 0;
    virtual bool normal(Vector3 point) = 0;
    virtual bool getTexture(Vector3 point) = 0;
};


#endif //RAYTRACER_OBJECT_HH
