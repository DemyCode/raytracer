//
// Created by mehdi on 28/02/2020.
//

#ifndef RAYTRACER_TRIANGLE_HH
#define RAYTRACER_TRIANGLE_HH


#include "object.hh"

class Triangle : public Object {
public:
    Triangle(Vector3 a, Vector3 b, Vector3 c, Vector3 an, Vector3 bn, Vector3 cn, TextureMaterial *textureMaterial);
    std::optional<Vector3> intersect(Ray ray) override;
    Vector3 normal(Vector3 point) override;
private:
    bool isintriangle(Vector3 point);
    bool sameside(Vector3 a, Vector3 b, Vector3 c, Vector3 point);
    Vector3 a_;
    Vector3 b_;
    Vector3 c_;
    Vector3 an_;
    Vector3 bn_;
    Vector3 cn_;
};


#endif //RAYTRACER_TRIANGLE_HH
