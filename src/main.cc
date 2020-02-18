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


int main()
{
    Sphere sphere1 = Sphere(Vector3(20, 0, 0), 5);
    std::vector<Object*> objects = std::vector<Object*>();
    objects.push_back(&sphere1);

    PointLight light1 = PointLight(Vector3(0, 0, 0));
    std::vector<Light*> lights = std::vector<Light*>();
    lights.push_back(&light1);

    size_t anglex = 90;
    size_t angley = 80;
    double zmin = 10;
    Vector3 location = Vector3(0, 0, 0);
    Vector3 targetv = Vector3(1, 0, 0);
    Vector3 upvector = Vector3(0, 1, 0);
    Camera camera = Camera(location, targetv, upvector, anglex, angley, zmin);

    targetv = targetv.normalize();
    upvector = upvector.normalize();
    Vector3 leftv = targetv.cross(upvector).normalize();
    double halfscreensizex = std::tan(camera.getAnglex() / 2) * zmin;
    double halfscreensizey = std::tan(camera.getAngley() / 2) * zmin;

    Scene scene = Scene(objects, lights, camera);

    int width = 1366;
    int height = 768;

    Image image = Image(width, height);


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Vector3 origin = camera.getLocation();
            Vector3 screenpoint = origin + camera.getTarget() * zmin;
            double wid2 = width / 2;
            double hei2 = height / 2;
            Vector3 leftpoint = screenpoint + leftv * halfscreensizex * ((j - wid2) / wid2);
            Vector3 uppoint = leftpoint + upvector * halfscreensizey * ((i - hei2) / hei2);
            Vector3 direction = uppoint - origin;
            Ray ray = Ray(origin, direction);
            ColorRGB colorRgb = scene.castRay(ray);
            image.setPixel(j, i, colorRgb);
        }
    }

    image.ppm_creator("output.ppm");

    return 0;
}
