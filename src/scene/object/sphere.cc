//
// Created by mehdi on 11/02/2020.
//

#include "sphere.hh"

Sphere::Sphere(Vector3 center, int r) {
    this->center_ = center;
    this->r_ = r;
}

Vector3* Sphere::intersect(Ray ray) {
    int a = this->center_.getX();
    int b = this->center_.getY();
    int c = this->center_.getZ();
    int r = this->r_;
    int alpha = ray.getPoint().getX();
    int beta = ray.getPoint().getY();
    int gamma = ray.getPoint().getZ();
    int vx = ray.getDirection().getX();
    int vy = ray.getDirection().getY();
    int vz = ray.getDirection().getZ();
    return nullptr;
}

bool Sphere::getTexture(Vector3 point) {
    return false;
}

bool Sphere::normal(Vector3 point) {
    return false;
}
