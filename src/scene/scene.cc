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
            Vector3 normaldir = objres->normal(point).normalize();
            double dotproduct = normaldir.dot(lightdir);
            newColor = newColor +
                    (objres->getTextureColor(point) *
                    objres->getTextureKd(point) *
                    dotproduct *
                    light->getIntensity());
            Vector3 reflectdir = ray.getDirection() - normaldir * ray.getDirection().dot(normaldir) * 2;
            double dotproduct2 = reflectdir.dot(lightdir);
            newColor = newColor +
                       ColorRGB("white") *
                       objres->getTextureKs(point) *
                       light->getIntensity() *
                       dotproduct2;
        }
    }
    return newColor;
}
