#ifndef POINT_H
#define POINT_H
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include "Tokenizer.h"
#include <string>
class Point{
private:
    float _x;
    float _y;
public:
    static int InstanceCount;
    float X() const;
    float Y() const;
    void SetX(float x);
    void SetY(float y);
public:
    Point();
    Point(float x, float y);
    ~Point();
    Point (const Point &other);
public:
    float CalcDistanceTo(const Point *other) const;
    static float CalcDistance(const Point *a, const Point *b);
public:
    std::string ToString() const;
    friend std::istream& operator >> (std::istream &in, Point &p);
    friend std::ostream& operator << (std::ostream &out, const Point& p);
public:
    static Point *Parse(std::string s);
};
#endif