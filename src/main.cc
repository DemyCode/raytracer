//
// Created by mehdi on 11/02/2020.
//

#include <iostream>
#include <math.h>

#include <utils/vector3.hh>
#include <scene/scene.hh>
#include <scene/object/object.hh>
#include <scene/object/sphere.hh>
#include <scene//light/pointlight.hh>
#include <utils/image.hh>
#include <scene/object/plane.hh>


int main()
{
    auto *shinyred = new UniformTexture(0.05, 1, ColorRGB("red"));
    auto *shinyyellow = new UniformTexture(0.1, 1, ColorRGB("yellow"));
    auto *shinyblue = new UniformTexture(0.05, 1, ColorRGB("blue"));
    Sphere sphere1 = Sphere(Vector3(50, 10, -20), 5, shinyred);
    Sphere sphere2 = Sphere(Vector3(50, 10, 0), 5, shinyyellow);
    Sphere sphere3 = Sphere(Vector3(50, 10, 20), 5, shinyblue);
    Plane plane = Plane(Vector3(0, 0, 0), Vector3(0, 0, 1), Vector3(1, 0, 0), shinyyellow);
    std::vector<Object*> objects = std::vector<Object*>();
    objects.push_back(&sphere1);
    objects.push_back(&sphere2);
    objects.push_back(&sphere3);
    objects.push_back(&plane);

    //PointLight light1 = PointLight(Vector3(0, 30, 30), 1, ColorRGB("white"));
    PointLight light2 = PointLight(Vector3(50, 40, 0), 1, ColorRGB("white"));
    std::vector<PointLight*> lights = std::vector<PointLight*>();
    //lights.push_back(&light1);
    lights.push_back(&light2);

    double anglex = 90;
    double angley = 60;

    double zmin = 10;
    Vector3 location = Vector3(0, 10, 0);
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
            int bounces = 2;
            ColorRGB colorRgb = scene.castRay(ray, location, uppoint, bounces);
            image.setPixel(j, height - i - 1, colorRgb);
        }
    }

    image.ppm_creator("output.ppm");

    return 0;
}
