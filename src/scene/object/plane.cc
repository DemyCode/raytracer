//
// Created by mehdi on 19/02/2020.
//

#include "plane.hh"

Plane::Plane(Vector3 point, Vector3 normal, TextureMaterial* textureMaterial)
{
    this->point_ = point;
    this->normal_ = normal.normalize();
    this->textureMaterial_ = textureMaterial;
}

std::optional<Vector3> Plane::intersect(Ray ray) {
//    double denom = this->normal_.dot(ray.getDirection());
//    if (denom > 1e-6)
//    {
//        Vector3 p0l0 = this->point_ - ray.getPoint();
//        double t = p0l0.dot(this->normal_) / denom;
//        return ray.getPoint() + ray.getDirection() * t;
//    }
//    return std::nullopt;
    
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