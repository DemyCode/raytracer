//
// Created by mehdi on 19/02/2020.
//

#include "plane.hh"

Plane::Plane(Vector3 a, Vector3 b, Vector3 c, Vector3 normal, TextureMaterial* textureMaterial)
{
    this->a_ = a;
    this->b_ = b;
    this->c_ = c;
    this->normal_ = normal;
    this->textureMaterial_ = textureMaterial;
}

std::optional<Vector3> Plane::intersect(Ray ray) {
    Vector3 AB = this->b_ - this->a_;
    Vector3 AC = this->c_ - this->a_;
    Vector3 crossed = AB.cross(AC);
    double A = crossed.getX();
    double B = crossed.getY();
    double C = crossed.getZ();
    double x0 = a_.getX();
    double y0 = a_.getY();
    double z0 = a_.getZ();
    double Vx = ray.getDirection().getX();
    double Vy = ray.getDirection().getY();
    double Vz = ray.getDirection().getZ();
    double Px = ray.getPoint().getX();
    double Py = ray.getPoint().getY();
    double Pz = ray.getPoint().getZ();

    double num = - A * Px + A * x0
                - B * Py + B * y0
                - C * Pz + C * z0;
    double denum = A * Vx + B * Vy + C * Vz;
    if (denum == 0)
        return std::nullopt;
    double t = num / denum;
    return Vector3(Vx * t + Px, Vy * t + Py, Vz * t + Pz);
}

Vector3 Plane::normal(Vector3 point) {
    (void) point;
    //return (this->b_ - this->a_).cross(this->c_ - this->a_);
    return this->normal_;
}