//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_OBJECT_HH
#define RAYTRACER_OBJECT_HH

#include <scene/texture/texturematerial.hh>
#include <utils/vector3.hh>

class Object {
    virtual bool intersect(Vector3 point, Vector3 vector) = 0;
    virtual bool normal(Vector3 point);
    virtual bool getTexture(Vector3 point);
};


#endif //RAYTRACER_OBJECT_HH
