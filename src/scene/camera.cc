//
// Created by mehdi on 11/02/2020.
//

#include "camera.hh"

Camera::Camera(Vector3 location, Vector3 target, Vector3 upvector) {
    this->location_ = location;
    this->target_ = target;
    this->upvector_ = upvector;
}
