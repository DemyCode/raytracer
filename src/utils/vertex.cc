//
// Created by mehdi on 28/02/2020.
//

#include "vertex.hh"

Vertex::Vertex(double x, double y, double z, std::optional<Vector3> normal) {
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
    this->normal_ = normal;
}
