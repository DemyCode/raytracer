//
// Created by mehdi on 19/02/2020.
//

#ifndef RAYTRACER_SQUARE_HH
#define RAYTRACER_SQUARE_HH


#include <scene/object/object.hh>

class Square : public Object {
public:
    std::optional<Vector3> intersect(Ray ray) override;
    Vector3 normal(Vector3 point) override;
    double getTextureKs(Vector3 point) override;
    double getTextureKd(Vector3 point) override;
    ColorRGB getTextureColor(Vector3 point) override;
};


#endif //RAYTRACER_SQUARE_HH
