//
// Created by mehdi on 28/02/2020.
//

#ifndef RAYTRACER_PARSER_HH
#define RAYTRACER_PARSER_HH

#include <regex>
#include <fstream>
#include <utils/vertex.hh>
#include <scene/texture/uniformtexture.hh>
#include <scene/object/triangle.hh>
#include <string>
#include <scene/object/object.hh>
#include <scene/texture/uniformtexture.hh>

class Parser {
public:
    Parser(std::string file);
    std::vector<Triangle *> getTriangles();
private:
    std::smatch matcher(std::string line, std::string regex);
    std::vector<Vector3> vertices_;
    std::vector<Vector3> vetricestexture_;
    std::vector<Vector3> normals_;
    std::vector<Triangle*> faces_;
};


#endif //RAYTRACER_PARSER_HH
