//
// Created by mehdi on 11/02/2020.
//

#include "pointlight.hh"


PointLight::PointLight(Vector3 position, double intensity) {
    this->position_ = position;
    this->intensity_ = intensity;
}

Vector3 PointLight::getPos() {
    return this->position_;
}

double PointLight::getIntensity()
{
    return this->intensity_;
}
