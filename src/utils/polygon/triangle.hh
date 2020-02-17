//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_TRIANGLE_HH
#define RAYTRACER_TRIANGLE_HH


#include <utils/vector3.hh>

class Triangle {
public:
    Triangle(Triangle const &) = default;
    Triangle(Vector3 p1, Vector3 p2, Vector3 p3);
private:
    Vector3 p1_;
    Vector3 p2_;
    Vector3 p3_;
};


#endif //RAYTRACER_TRIANGLE_HH
