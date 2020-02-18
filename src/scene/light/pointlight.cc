//
// Created by mehdi on 11/02/2020.
//

#include "pointlight.hh"


PointLight::PointLight(Vector3 position) {
    this->position_ = position;
}

Vector3 PointLight::getPos() {
    return this->position_;
}
