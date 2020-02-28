//
// Created by mehdi on 28/02/2020.
//

#ifndef RAYTRACER_VERTEX_HH
#define RAYTRACER_VERTEX_HH


#include <optional>
#include "vector3.hh"

class Vertex : public Vector3{
public:
    Vertex(double x, double y, double z, std::optional<Vector3> normal);
private:
    std::optional<Vector3> normal_;
};


#endif //RAYTRACER_VERTEX_HH
