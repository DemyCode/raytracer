//
// Created by mehdi on 19/02/2020.
//

#ifndef RAYTRACER_PLANE_HH
#define RAYTRACER_PLANE_HH


#include <scene/object/object.hh>

class Plane : public Object {
public:
    Plane(Vector3 a, Vector3 b, Vector3 c, Vector3 normal, TextureMaterial* textureMaterial);
    std::optional<Vector3> intersect(Ray ray) override;
    Vector3 normal(Vector3 point) override;
private:
    Vector3 a_;
    Vector3 b_;
    Vector3 c_;
    Vector3 normal_;
};


#endif //RAYTRACER_PLANE_HH
