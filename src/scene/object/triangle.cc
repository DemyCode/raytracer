//
// Created by mehdi on 28/02/2020.
//

#include "triangle.hh"

Triangle::Triangle(Vertex a, Vertex b, Vertex c, TextureMaterial *textureMaterial) {
    this->a_ = a;
    this->b_ = b;
    this->c_ = c;
    this->textureMaterial_ = textureMaterial;
}

std::optional<Vector3> Triangle::intersect(Ray ray) {
    Vector3 AB = this->b_ - this->a_;
    Vector3 AC = this->c_ - this->a_;
    Vector3 crossed = AB.cross(AC);
    double A = crossed.getX();
    double B = crossed.getY();
    double C = crossed.getZ();
    double x0 = this->a_.getX();
    double y0 = this->a_.getY();
    double z0 = this->a_.getZ();
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
    Vector3 intersectionpoint = Vector3(Vx * t + Px, Vy * t + Py, Vz * t + Pz);
    if (isintriangle(intersectionpoint))
        return intersectionpoint;
    return std::nullopt;
}

bool Triangle::isintriangle(Vector3 point)
{
    return sameside(this->a_, this->b_, this->c_, point) &&
            sameside(this->c_, this->a_, this->b_, point) &&
            sameside(this->b_, this->c_, this->a_, point);
}

bool Triangle::sameside(Vector3 a, Vector3 b, Vector3 c, Vector3 point)
{
    Vector3 AB = b - a;
    Vector3 AC = c - a;
    Vector3 AP = point - a;
    return AB.cross(AP).dot(AB.cross(AC)) >= 0;
}

Vector3 Triangle::normal(Vector3 point)
{
    (void) point;
    return this->a_.getNormal().value();
}
