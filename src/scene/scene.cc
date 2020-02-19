//
// Created by mehdi on 11/02/2020.
//

#include "scene.hh"

Scene::Scene(std::vector<Object*> objects, std::vector<PointLight*> lights, Camera camera) {
    this->objects_ = objects;
    this->lights_ = lights;
    this->camera_ = camera;
}

ColorRGB Scene::castRay(Ray ray) {
    std::optional<Vector3> pointresult = std::nullopt;
    Object* objres = nullptr;
    double dist = 0;
    for (auto & object : this->objects_)
    {
        std::optional<Vector3> var = object->intersect(ray);
        if (var)
        {
            double newdist = var->dist(ray.getPoint());
            if (newdist > dist)
            {
                pointresult = var;
                dist = newdist;
                objres = object;
            }
        }
    }

    ColorRGB newColor = ColorRGB(0, 0, 0);
    if (pointresult && objres)
    {
        Vector3 point = pointresult.value();
        for (auto & light : this->lights_)
        {
            Vector3 lightdir = (light->getPos() - point).normalize();
            double dotproduct = objres->normal(point).normalize().dot(lightdir);
            newColor = newColor +
                    (objres->getTextureColor(point) *
                    objres->getTextureKd(point) *
                    dotproduct *
                    light->getIntensity());
            
        }
    }
    return newColor;
}
