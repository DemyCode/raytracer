//
// Created by mehdi on 11/02/2020.
//

#include "uniformtexture.hh"


UniformTexture::UniformTexture(double ks, double kd, ColorRGB rgb) {
    this->ks_ = ks;
    this->kd_ = kd;
    this->rgb_ = rgb;
}

double UniformTexture::getTextureKs(Vector3 point) {
    (void) point;
    return this->ks_;
}

double UniformTexture::getTextureKd(Vector3 point) {
    (void) point;
    return this->kd_;
}

ColorRGB UniformTexture::getTextureColor(Vector3 point) {
    (void) point;
    return this->rgb_;
}
