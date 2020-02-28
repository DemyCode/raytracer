#MAKE

# add_subdirectory(polygon)

set(utils_src
        vector3.cc
        color.cc
        image.cc
        ray.cc)

add_library(utils ${utils_src})