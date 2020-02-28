//
// Created by mehdi on 28/02/2020.
//

#include <regex>
#include "parser.hh"

Parser::Parser(std::string file) {
    std::regex rgx("*\n");
    std::smatch linematch;
    for (const auto & i : linematch)
    {
        std::string line = i;
        std::regex comment("#*");
        std::regex vertex("v*");
        //std::regex vtexture("vt*");
        std::regex vnormal("vn*");
        std::regex face("f*");
        std::regex group("g*");
        std::regex usemtl("usemtl*");
        std::smatch smatch;
        std::regex_search(line, smatch, comment);
        if (!smatch.empty())
            continue;
        std::regex_search(line, smatch, vertex);
        if (!smatch.empty())
        {
            std::regex regpoint("[+-]?([0-9]*[.])?[0-9]+");
            std::regex_search(line, smatch, regpoint);
            Vector3 point = Vector3(std::stod(smatch[0]), std::stod(smatch[1]), std::stod(smatch[2]));
            this->vertices_.push_back(point);
            continue;
        }
        std::regex_search(line, smatch, vnormal);
        if (!smatch.empty())
        {
            std::regex regpoint("[+-]?([0-9]*[.])?[0-9]+");
            std::regex_search(line, smatch, regpoint);
            Vector3 point = Vector3(std::stod(smatch[0]), std::stod(smatch[1]), std::stod(smatch[2]));
            this->normals_.push_back(point);
            continue;
        }
//        std::regex_search(line, smatch, vtexture);
//        if (!smatch.empty())
//        {
//            std::regex regpoint("[+-]?([0-9]*[.])?[0-9]+");
//            std::regex_search(line, smatch, regpoint);
//            Vector3 point = Vector3(std::stod(smatch[0]), std::stod(smatch[1]), std::stod(smatch[2]));
//            this->normals_.push_back(point);
//            continue;
//        }
        std::regex_search(line, smatch, face);
        if (!smatch.empty())
        {
            std::string number = "[0-9]+";
            std::regex facedefintion(number + "|" + // only vertice
            number + "//" + number + "|" + // vertice + normal
            number + "/" + number + "|" + // vertice + texture
            number + "/" + number + "/" + number); // vertice + texture + number
            std::smatch indexmatch;
            std::regex_search(line, indexmatch, facedefintion);
            if (indexmatch.size() != 3)
                continue;
            for (size_t j = 0; j < indexmatch.size(); j++)
            {
                std::string tempstring = indexmatch[j];
                std::regex _1(number);
                std::regex _2(number + "//" + number);
                std::regex _3(number + "/" + number);
                std::regex _4(number + "/" + number + "/" + number);
                std::smatch facematcher;
                std::regex_search(tempstring, facematcher, _1);
                if (!facematcher.empty())
                {

                }
            }
        }
    }
}
