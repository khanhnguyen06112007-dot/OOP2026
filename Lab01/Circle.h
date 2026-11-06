#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
#pragma once
class Circle{
private:
    Point *_center;
    float _radius;
public:
    const double PI = 3.14;
    Point *Center();
    float Radius();
    void SetCenter(Point *value);
    void SetRadius(float value);

    float Diameter();
    float Perimeter();
    float Area();

    Circle();
    ~Circle();
};
#endif