//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_SCENE_HH
#define RAYTRACER_SCENE_HH

#include <vector>

#include <scene/object/object.hh>
#include <scene/light/light.hh>
#include <scene/camera.hh>

class Scene {
public:
    Scene(std::vector<Object*> objects, std::vector<Light*> lights, Camera camera);
private:
    std::vector<Object*> objects_;
    std::vector<Light*> lights_;
    Camera camera_;
};


#endif //RAYTRACER_SCENE_HH
