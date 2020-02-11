//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_VECTOR3_H
#define RAYTRACER_VECTOR3_H

class Vector3
{
public:
    Vector3(int x, int y, int z);
    Vector3 operator+(Vector3 v1, Vector3 v2);
    Vector3 operator-(Vector3 v1, Vector3 v2);
    Vector3 operator*(Vector3 v1, Vector3 v2);
    Vector3 operator/(Vector3 v1, Vector3 v2);
private:
    int x_;
    int y_;
    int z_;
};

#endif //RAYTRACER_VECTOR3_H
