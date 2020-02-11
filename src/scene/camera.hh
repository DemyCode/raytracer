//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_CAMERA_HH
#define RAYTRACER_CAMERA_HH

#include <utils/vector3.hh>

class Camera {
public:
    Camera(Vector3 location, Vector3 target, Vector3 upvector);

private:
    Vector3 location_;
    Vector3 target_;
    Vector3 upvector_;
};


#endif //RAYTRACER_CAMERA_HH
