//
// Created by mehdi on 11/02/2020.
//

#include "vector3.hh"

Vector3::Vector3(int x, int y, int z)
{
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
}

Vector3 Vector3::operator+(Vector3 v) {
    return Vector3(this->x_ + v.x_, this->y_ + v.y_, this->z_ + v.z_);
}

Vector3 Vector3::operator-(Vector3 v) {
    return Vector3(this->x_ - v.x_, this->y_ - v.y_, this->z_ - v.z_);
}

Vector3 Vector3::operator*(Vector3 v) {
    return Vector3(this->x_ * v.x_, this->y_ * v.y_, this->z_ * v.z_);
}

Vector3 Vector3::operator/(Vector3 v) {
    return Vector3(this->x_ / v.x_, this->y_ / v.y_, this->z_ / v.z_);
}

std::ostream &Vector3::operator<<(std::ostream &out) {
    return out << "(" << this->x_ << "," << this->y_ << "," << this->z_ << ")";
}