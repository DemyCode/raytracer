//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_VECTOR3_H
#define RAYTRACER_VECTOR3_H

#include <iostream>

class Vector3
{
public:
    Vector3(float x, float y, float z);
    Vector3() = default;
    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(const Vector3& v) const;
    Vector3 operator/(const Vector3& v) const;
    friend std::ostream& operator<<(std::ostream &out, const Vector3 &vect);

    float getX();
    float getY();
    float getZ();

private:
    float x_;
    float y_;
    float z_;
};

#endif //RAYTRACER_VECTOR3_H
