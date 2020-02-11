//
// Created by mehdi on 11/02/2020.
//

#include "color.hh"

ColorRGB::ColorRGB(int r, int g, int b)
{
    this->r_ = r;
    this->g_ = g;
    this->b_ = b;
}

int ColorRGB::getR() {
    return r_;
}

int ColorRGB::getG() {
    return g_;
}

int ColorRGB::getB() {
    return b_;
}

void ColorRGB::setR(int r) {
    this->r_ = r;
}

void ColorRGB::setG(int g) {
    this->g_ = g;
}

void ColorRGB::setB(int b) {
    this->b_ = b;
}
