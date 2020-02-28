//
// Created by mehdi on 11/02/2020.
//

#include <iostream>
#include <math.h>

#include <utils/vector3.hh>
#include <scene/scene.hh>
#include <scene/object/object.hh>
#include <scene/light/pointlight.hh>
#include <utils/image.hh>
#include <utils/parser/parser.hh>
#include <scene/object/plane.hh>
#include <scene/object/sphere.hh>
#include <scene/object/triangle.hh>


int main()
{
//    auto *shinyred = new UniformTexture(0.2, 1, ColorRGB("red"), 1);
//    auto *shinygreen = new UniformTexture(0.2, 1, ColorRGB("green"), 1);
    //auto *shinyblue = new UniformTexture(0.2, 1, ColorRGB("blue"), 1);
//    auto *shinywhite = new UniformTexture(0.2, 1, ColorRGB("white"), 1);
//    auto *shinyblue = new UniformTexture(0.2, 1, ColorRGB("blue"), 1);
//    auto *mirror = new UniformTexture(1.0, 0, ColorRGB("white"), 5);
//    Sphere sphere1 = Sphere(Vector3(50, 10, 0), 5, mirror);
//    Sphere sphere2 = Sphere(Vector3(50, 10, 20), 5, mirror);
//    Sphere sphere3 = Sphere(Vector3(50, 10, -20), 5, mirror);
//    Plane plane = Plane(Vector3(0, 0, -20), Vector3(0, 0, 1), shinywhite);
//    Plane plane2 = Plane(Vector3(0, 0, 20), Vector3(0, 0, -1), shinywhite);
    //Plane plane3 = Plane(Vector3(100, 0, 0), Vector3(-1, 0, 0), mirror);
    //Plane plane4 = Plane(Vector3(0, -20, 0), Vector3(0, 1, 0), shinyblue);
    Parser parser = Parser("../objects/teapot.obj");
    std::vector<Triangle*> triangles = parser.getTriangles();

//    Plane plane5 = Plane(Vector3(0, 20, 0), Vector3(0, -1, 0), shinywhite);

//    Plane plane4 = Plane(Vector3(, 0, 0), Vector3(1, 0, 0), shinywhite);
    std::vector<Object*> objects = std::vector<Object*>();
//    objects.push_back(&sphere1);
//    objects.push_back(&sphere2);
//    objects.push_back(&sphere3);
//    objects.push_back(&plane);
//    objects.push_back(&plane2);
    //objects.push_back(&plane3);
    //objects.push_back(&plane4);
//    objects.push_back(&plane5);
    objects.insert(objects.end(), triangles.begin(), triangles.end());

//    PointLight light1 = PointLight(Vector3(30, 30, 10), 1, ColorRGB("white"));
    PointLight light2 = PointLight(Vector3(-500, 100, 100), 1, ColorRGB("white"));
//    PointLight light1 = PointLight(Vector3(75, 10, 10), 1, ColorRGB("blue"));
    std::vector<PointLight*> lights = std::vector<PointLight*>();
//    lights.push_back(&light1);
    lights.push_back(&light2);

    double anglex = 90;
    double angley = 60;
    int bounces = 1;

    double zmin = 10;
    Vector3 location = Vector3(-500, 30, 0);
    Vector3 targetv = Vector3(1, 0, 0);
    Vector3 upvector = Vector3(0, 1, 0);
    Camera camera = Camera(location, targetv, upvector, anglex, angley, zmin);

    targetv = targetv.normalize();
    upvector = upvector.normalize();
    Vector3 leftv = targetv.cross(upvector).normalize();
    double halfscreensizex = std::tan((camera.getAnglex() / 2.0) * (M_PI / 180)) * zmin;
    double halfscreensizey = std::tan((camera.getAngley() / 2.0) * (M_PI / 180)) * zmin;

    Scene scene = Scene(objects, lights, camera);

    int width = 1920;
    int height = 1080;

    Image image = Image(width, height);

    for (int i = 0; i < height; i++)
    {
        std::cout << "Treating : " << width * i << "/" << height * width << std::endl;
        for (int j = 0; j < width; j++)
        {
            Vector3 origin = camera.getLocation();
            Vector3 screenpoint = origin + (targetv * zmin);
            double wid2 = width / 2;
            double hei2 = height / 2;
            Vector3 leftpoint = screenpoint + (leftv * halfscreensizex * ((j - wid2) / wid2));
            Vector3 uppoint = leftpoint + (upvector * halfscreensizey * ((i - hei2) / hei2));
            Vector3 direction = uppoint - origin;
            Ray ray = Ray(origin, direction);
            ColorRGB colorRgb = scene.castRay(ray, bounces);
            image.setPixel(j, height - i - 1, colorRgb);
        }
    }

    image.ppm_creator("output.ppm");

    return 0;
}
