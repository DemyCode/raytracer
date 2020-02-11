//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_VECTOR3_H
#define RAYTRACER_VECTOR3_H

#include <iostream>

class Vector3
{
public:
    Vector3(int x, int y, int z);
    Vector3 operator+(Vector3 v);
    Vector3 operator-(Vector3 v);
    Vector3 operator*(Vector3 v);
    Vector3 operator/(Vector3 v);
    std::ostream& operator<<(std::ostream &out);
private:
    int x_;
    int y_;
    int z_;
};

#endif //RAYTRACER_VECTOR3_H
