//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

class ColorRGB
{
public:
    ColorRGB(int r, int g, int b);
    int getR();
    int getG();
    int getB();
    void setR(int r);
    void setG(int g);
    void setB(int b);
private:
    int r_;
    int g_;
    int b_;
};

#endif //RAYTRACER_COLOR_H
