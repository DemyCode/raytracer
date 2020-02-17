//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_UNIFORMTEXTURE_HH
#define RAYTRACER_UNIFORMTEXTURE_HH

#include <scene/texture/texturematerial.hh>

class UniformTexture : public TextureMaterial {
    void getTexture() override;
};


#endif //RAYTRACER_UNIFORMTEXTURE_HH
