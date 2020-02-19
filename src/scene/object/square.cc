//
// Created by mehdi on 19/02/2020.
//

#include "square.hh"

Vector3 Square::normal(Vector3 point) {
    return Vector3();
}

std::optional<Vector3> Square::intersect(Ray ray) {
    return std::optional<Vector3>();
}

double Square::getTextureKs(Vector3 point) {
    return 0;
}

double Square::getTextureKd(Vector3 point) {
    return 0;
}

ColorRGB Square::getTextureColor(Vector3 point) {
    return ColorRGB();
}
