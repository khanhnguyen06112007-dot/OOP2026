#ifndef POINT_H
#define POINT_H
#pragma once
#include <math.h>

class Point{
private:
    float _x;
    float _y;
public:
    float X();
    float Y();
    void SetX(float value);
    void SetY(float value);
    Point();
    Point(float, float);
    ~Point();
    float CalcDistanceTo(const Point *other);
};
#endif