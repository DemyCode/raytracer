//
// Created by mehdi on 11/02/2020.
//

#include "scene.hh"

Scene::Scene(std::vector<Object*> objects, std::vector<PointLight*> lights, Camera camera) {
    this->objects_ = objects;
    this->lights_ = lights;
    this->camera_ = camera;
}

std::optional<std::tuple<Vector3, Object*>> Scene::trace(Ray ray, Vector3 origin, Vector3 screen)
{
    double epsilon = 0.01;
    origin = origin + ray.getDirection().normalize() * epsilon;
    std::optional<Vector3> pointresult = std::nullopt;
    Object* objres = nullptr;
    double dist = 999999999999;
    for (auto & object : this->objects_)
    {
        std::optional<Vector3> var = object->intersect(ray);
        if (var)
        {
            double newdist = var->dist(ray.getPoint());
            Vector3 OriginScreen = (screen - origin).normalize();
            Vector3 ScreenPoint = (var.value() - screen).normalize();
            double same = OriginScreen.dot(ScreenPoint);
            if (newdist < dist && 0.9 <= same && same <= 1.1)
            {
                pointresult = var;
                dist = newdist;
                objres = object;
            }
        }
    }
    if (pointresult && objres)
        return std::make_tuple(pointresult.value(), objres);
    return std::nullopt;
}

ColorRGB Scene::castRay(Ray ray, Vector3 origin, Vector3 screen, int bounces) {
    if (bounces == 0)
        return ColorRGB("black");

    ColorRGB newColor = ColorRGB(0, 0, 0);
    std::optional<std::tuple<Vector3, Object*>> tuple = this->trace(ray, origin, screen);

    if (tuple)
    {
        Vector3 pointresult = std::get<0>(tuple.value());
        Object *objres = std::get<1>(tuple.value());
        for (auto & light : this->lights_)
        {
            Vector3 lightdir = (light->getPos() - pointresult).normalize();
            std::optional<std::tuple<Vector3, Object*>> shadow = this->trace(Ray(pointresult, lightdir), pointresult, pointresult + lightdir);
            if (shadow)
            {
                newColor = ColorRGB("black");
            }
            else
            {
                Vector3 normaldir = objres->normal(pointresult).normalize();
                double dotproduct = normaldir.dot(lightdir);
                newColor = newColor +
                           (objres->getTextureColor(pointresult) *
                            objres->getTextureKd(pointresult) *
                            dotproduct *
                            light->getIntensity());

                Vector3 reflectdir = ray.getDirection() - normaldir * ray.getDirection().dot(normaldir) * 2;
                double dotproduct2 = reflectdir.dot(lightdir);
                newColor = newColor +
                           light->getColorRgb() * objres->getTextureKs(pointresult) *
                           light->getIntensity() *
                           dotproduct2;

                newColor = newColor +
                           castRay(Ray(pointresult, reflectdir), pointresult, pointresult + reflectdir, bounces - 1) * objres->getTextureKs(pointresult);
            }
        }
    }
    return newColor;
}
