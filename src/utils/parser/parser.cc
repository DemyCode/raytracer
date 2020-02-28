//
// Created by mehdi on 28/02/2020.
//

#include "parser.hh"

Parser::Parser(std::string path) {
    std::ifstream file(path);
    if (!file.is_open())
        std::cerr << "File not found" << std::endl;
    for (std::string line; std::getline(file, line); )
    {
        std::smatch smatch;
        smatch = this->matcher(line, "#.*");
        if (!smatch.empty())
            continue;
        smatch = this->matcher(line, "v.*");
        if (!smatch.empty()) {
            smatch = this->matcher(line, "[+-]?([0-9]*[.])?[0-9]+");
            std::string val0 = smatch[0];
            Vector3 point = Vector3(std::stod(val0), std::stod(smatch[1]), std::stod(smatch[2]));
            this->vertices_.push_back(point);
            continue;
        }
        smatch = this->matcher(line, "vn.*");
        if (!smatch.empty()) {
            smatch = this->matcher(line, "[+-]?([0-9]*[.])?[0-9]+");
            Vector3 point = Vector3(std::stod(smatch[0]), std::stod(smatch[1]), std::stod(smatch[2]));
            this->normals_.push_back(point);
            continue;
        }
        smatch = this->matcher(line, "f.*");
        if (!smatch.empty()) {
            std::string number = "[0-9]+";
            smatch = this->matcher(line, number + "|" + // only vertice
                                         number + "//" + number + "|" + // vertice + normal
                                         number + "/" + number + "|" + // vertice + texture
                                         number + "/" + number + "/" + number); // vertice + normal + texture
            if (smatch.size() != 3)
                continue;
            std::vector<Vertex> res;
            for (const auto & j : smatch)
            {
                std::smatch valuematch;
                valuematch = this->matcher(j, number + "//" + number);
                if (!valuematch.empty())
                {
                    std::smatch numbers = this->matcher(j, number);
                    Vector3 point = this->vertices_[std::stoi(numbers[0])];
                    Vector3 normal = this->normals_[std::stoi(numbers[1])];
                    res.emplace_back(point.getX(), point.getY(), point.getZ(), normal);
                    continue;
                }
                valuematch = this->matcher(j, number + "/" + number);
                if (!valuematch.empty())
                {
                    std::smatch numbers = this->matcher(j, number);
                    Vector3 point = this->vertices_[std::stoi(numbers[0])];
                    // Vector3 normal = this->normals_[std::stoi(numbers[1])];
                    res.emplace_back(point.getX(), point.getY(), point.getZ(), std::nullopt);
                    continue;
                }
                valuematch = this->matcher(j, number + "/" + number + "/" + number);
                if (!valuematch.empty())
                {
                    std::smatch numbers = this->matcher(j, number);
                    Vector3 point = this->vertices_[std::stoi(numbers[0])];
                    Vector3 normal = this->normals_[std::stoi(numbers[2])];
                    res.emplace_back(point.getX(), point.getY(), point.getZ(), normal);
                    continue;
                }
                valuematch = this->matcher(j, number + "//" + number);
                if (!valuematch.empty())
                {
                    Vector3 point = this->vertices_[std::stoi(j)];
                    res.emplace_back(point.getX(), point.getY(), point.getZ(), std::nullopt);
                    continue;
                }
            }
            this->faces_.push_back(new Triangle(res[0], res[1], res[2],
                                            new UniformTexture(1.0, 1.0, ColorRGB("red"), 1.0)));
        }
    }
}

std::vector<Triangle *> Parser::getTriangles()
{
    return this->faces_;
}

std::smatch Parser::matcher(std::string line, std::string regex)
{
    std::regex reg(regex);
    std::smatch smatch;
    std::regex_search(line, smatch, reg);
    return smatch;
}