//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_TEXTUREMATERIAL_HH
#define RAYTRACER_TEXTUREMATERIAL_HH


class TextureMaterial {
    virtual void getTexture() = 0;
private:
    float kd;
    float ks;
};


#endif //RAYTRACER_TEXTUREMATERIAL_HH
