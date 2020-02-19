//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_OBJECT_HH
#define RAYTRACER_OBJECT_HH

#include <optional>
#include <tuple>

#include <scene/texture/texturematerial.hh>
#include <utils/vector3.hh>
#include <utils/ray.hh>

class Object {
public:
    virtual std::optional<Vector3> intersect(Ray ray) = 0;
    virtual Vector3 normal(Vector3 point) = 0;
    virtual double getTextureKs(Vector3 point) = 0;
    virtual double getTextureKd(Vector3 point) = 0;
    virtual ColorRGB getTextureColor(Vector3 point) = 0;

protected:
    TextureMaterial *textureMaterial_;
};


#endif //RAYTRACER_OBJECT_HH
