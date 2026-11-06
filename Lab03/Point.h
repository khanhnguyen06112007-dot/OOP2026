#ifndef POINT_H
#define POINT_H
#include <cmath>
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

    Point();
    Point(float x, float y);
    ~Point();
    Point (const Point &other);
    float CalcDistanceTo(const Point *other) const;
    static float CalcDistance(const Point *a, const Point *b);
};
#endif