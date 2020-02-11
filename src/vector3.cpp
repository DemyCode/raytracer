//
// Created by mehdi on 11/02/2020.
//

#include "vector3.h"

Vector3::Vector3(int x, int y, int z)
{
    this.x_ = x;
    this.y_ = y;
    this.z_ = z;
}

Vector3 Vector3::operator+(Vector3 v1, Vector3 v2)
{
    return Vector3(v1.x_ + v2.x_, v1.y_ + v2.y_, v1.z_ + v2.z_);
}

Vector3 Vector3::operator*(Vector3 v1, Vector3 v2)
{
    return Vector3(v1.x_ * v2.x_, v1.y_ * v2.y_, v1.z_ * v2.z_);
}

Vector3 Vector3::operator-(Vector3 v1, Vector3 v2)
{
    return Vector3(v1.x_ - v2.x_, v1.y_ - v2.y_, v1.z_ - v2.z_);
}

Vector3 Vector3::operator/(Vector3 v1, Vector3 v2)
{
    return Vector3(v1.x_ / v2.x_, v1.y_ / v2.y_, v1.z_ / v2.z_);
}