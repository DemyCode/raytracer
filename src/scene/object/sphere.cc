//
// Created by mehdi on 11/02/2020.
//

#include "sphere.hh"

Sphere::Sphere(Vector3 &center, double r) {
    this->center_ = center;
    this->r_ = r;
}

Sphere::Sphere(Vector3 center, double r) {
    this->center_ = center;
    this->r_ = r;
}

std::optional<Vector3> Sphere::intersect(Ray ray) {
    double Oa = this->center_.getX();
    double Ob = this->center_.getY();
    double Oc = this->center_.getZ();
    double r = this->r_;
    double Pa = ray.getPoint().getX();
    double Pb = ray.getPoint().getY();
    double Pc = ray.getPoint().getZ();
    double Va = ray.getDirection().getX();
    double Vb = ray.getDirection().getY();
    double Vc = ray.getDirection().getZ();

    double a =
            Va * Va +
            Vb * Vb +
            Vc * Vc;
    double b =
            Pa * Va + Pa * Va - Va * Oa - Oa * Va +
            Pb * Vb + Pb * Vb - Vb * Ob - Ob * Vb +
            Pc * Vc + Pc * Vc - Vc * Oc - Oc * Vc;
    double c =
            Pa * Pa - Pa * Oa - Pa * Oa + Oa * Oa +
            Pb * Pb - Pb * Ob - Pb * Ob + Ob * Ob +
            Pc * Pc - Pc * Oc - Pc * Oc + Oc * Oc - r * r;
    double delta = b * b - 4 * a * c;
    if (delta == 0)
    {
        double t = (-1 * b) / (2 * a);
        return Vector3(Pa + Va * t, Pb + Vb * t, Pc + Vc * t);
    }
    if (delta > 0)
    {
        double t1 = (b + std::sqrt(delta)) / (2 * a);
        double t2 = (b - std::sqrt(delta)) / (2 * a);
        Vector3 firstpoint = Vector3(Pa + Va * t1, Pb + Vb * t1, Pc + Vc * t1);
        Vector3 secondpoint = Vector3(Pa + Va * t2, Pb + Vb * t2, Pc + Vc * t2);
        if (firstpoint.dist(ray.getPoint()) < secondpoint.dist(ray.getPoint())) {
            return firstpoint;
        }
        return secondpoint;
    }
    return std::nullopt;
}

bool Sphere::getTexture(Vector3 point) {
    (void) point;
    return false;
}

bool Sphere::normal(Vector3 point) {
    (void) point;
    return false;
}
