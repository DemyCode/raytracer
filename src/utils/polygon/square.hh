//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_SQUARE_HH
#define RAYTRACER_SQUARE_HH


#include <utils/vector3.hh>

class Square {
public:
    Square(Square const &) = default;
    Square(Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4);
private:
    Vector3 p1_;
    Vector3 p2_;
    Vector3 p3_;
    Vector3 p4_;
};


#endif //RAYTRACER_SQUARE_HH
