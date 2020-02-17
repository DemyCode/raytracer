//
// Created by mehdi on 11/02/2020.
//

#include "vector3.hh"

Vector3::Vector3(float x, float y, float z)
{
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
}

Vector3 Vector3::operator+(const Vector3& v) const {
    return Vector3(this->x_ + v.x_, this->y_ + v.y_, this->z_ + v.z_);
}

Vector3 Vector3::operator-(const Vector3& v) const {
    return Vector3(this->x_ - v.x_, this->y_ - v.y_, this->z_ - v.z_);
}

Vector3 Vector3::operator*(const Vector3& v) const {
    return Vector3(this->x_ * v.x_, this->y_ * v.y_, this->z_ * v.z_);
}

Vector3 Vector3::operator/(const Vector3& v) const {
    return Vector3(this->x_ / v.x_, this->y_ / v.y_, this->z_ / v.z_);
}

std::ostream &operator<<(std::ostream &out, const Vector3 &vect) {
    return out << "(" << vect.x_ << "," << vect.y_ << "," << vect.z_ << ")";
}

float Vector3::getX() {
    return x_;
}

float Vector3::getY() {
    return y_;
}

float Vector3::getZ() {
    return z_;
}