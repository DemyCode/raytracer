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

ColorRGB ColorRGB::operator*(double val) {
    return ColorRGB((int)(this->r_ * val), (int)(this->g_ * val), (int)(this->b_ * val));
}

ColorRGB ColorRGB::operator+(const ColorRGB colorRgb) const {
    return ColorRGB(
            this->r_ + colorRgb.r_ ? this->r_ + colorRgb.r_ <= 255 : 255,
            this->g_ + colorRgb.g_ ? this->g_ + colorRgb.g_ <= 255 : 255,
            this->b_ + colorRgb.b_ ? this->b_ + colorRgb.b_ <= 255 : 255);
}
