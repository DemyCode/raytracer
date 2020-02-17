//
// Created by mehdi on 11/02/2020.
//

#include "scene.hh"

Scene::Scene(std::vector<Object*> objects, std::vector<Light*> lights, Camera camera) {
    this->objects_ = objects;
    this->lights_ = lights;
    this->camera_ = camera;
}
