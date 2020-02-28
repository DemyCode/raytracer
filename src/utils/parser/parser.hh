//
// Created by mehdi on 28/02/2020.
//

#ifndef RAYTRACER_PARSER_HH
#define RAYTRACER_PARSER_HH

#include <regex>
#include <string>
#include <utils/vector3.hh>

class Parser {
public:
    Parser(std::string file);
private:
    std::vector<Vector3> vertices_;
    std::vector<Vector3> vetricestexture_;
    std::vector<Vector3> normals_;
};


#endif //RAYTRACER_PARSER_HH
