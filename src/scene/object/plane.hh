//
// Created by mehdi on 19/02/2020.
//

#ifndef RAYTRACER_PLANE_HH
#define RAYTRACER_PLANE_HH


#include <scene/object/object.hh>

class Plane : public Object {
public:
    Plane(Vector3 point, Vector3 normal, TextureMaterial* textureMaterial);
    std::optional<Vector3> intersect(Ray ray) override;
    Vector3 normal(Vector3 point) override;
private:
    Vector3 point_;
    Vector3 normal_;
};


#endif //RAYTRACER_PLANE_HH
