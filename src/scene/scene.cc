//
// Created by mehdi on 11/02/2020.
//

#include "scene.hh"

Scene::Scene(std::vector<Object*> objects, std::vector<Light*> lights, Camera camera) {
    this->objects_ = objects;
    this->lights_ = lights;
    this->camera_ = camera;
}

ColorRGB Scene::castRay(Ray ray) {
    std::optional<Vector3> result = std::nullopt;
    double dist = 0;
    for (auto & object : this->objects_)
    {
        std::optional<Vector3> var = object->intersect(ray);
        if (var)
        {
            double newdist = var->dist(ray.getPoint());
            if (newdist > dist)
            {
                result = var;
                dist = newdist;
            }
        }
    }
    if (result)
        return ColorRGB(255, 255, 255);
    return ColorRGB(0, 0, 0);
}
