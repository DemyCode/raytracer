//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_SCENE_HH
#define RAYTRACER_SCENE_HH

#include <optional>
#include <vector>

#include <scene/object/object.hh>
#include <scene/light/light.hh>
#include <scene/camera.hh>
#include <utils/color.hh>
#include <scene/light/pointlight.hh>
#include <scene/object/triangle.hh>

class Scene {
public:
    Scene(std::vector<Object*> objects, std::vector<PointLight*> lights, Camera camera);
    std::vector<Object*> getObjects(){ return this->objects_; }
    std::vector<PointLight*> getLights(){ return this->lights_; }
    Camera getCamera(){ return this->camera_; }
    ColorRGB castRay(Ray ray, int bounces);
private:
    std::vector<Object*> objects_;
    std::vector<PointLight*> lights_;
    Camera camera_;

    std::optional<std::tuple<Vector3, Object *>> trace(Ray ray, double maxdistance);
};


#endif //RAYTRACER_SCENE_HH
