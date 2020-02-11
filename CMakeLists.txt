#MAKE

cmake_minimum_required(VERSION 3.0)
project(raytracer LANGUAGES CXX)
option(BUILD_DEBUG "Build with debug compile options." OFF)
option(BUILD_TEST "Build with the package as well as the tests." OFF)
set(BUILD_SHARED_LIBS ON)

if (BUILD_DEBUG)
    add_compile_options(-Wall -Wextra -pedantic -Werror -std=c++17 -g3 -D RAY_DEBUG -fno-inline -O0)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror -std=c++17 -O3)
endif ()

include_directories(src)

add_subdirectory(src)

add_executable(raytracer src/main.cc)

target_link_libraries(raytracer utils light object texture scene)

if (BUILD_TEST)
    add_subdirectory(tests)
endif (BUILD_TEST)