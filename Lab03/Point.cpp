#include "Point.h"

float Point::X() const{
    return _x;
}

float Point::Y() const{
    return _y;
}

void Point::SetX(float x){
    _x = x;
}

void Point::SetY(float y){
    _y = y;
}

Point::Point(){
    _x = _y = 0;
    Point::InstanceCount++;
}

Point::Point(float x, float y){
    _x = x;
    _y = y;
    Point::InstanceCount++;
}

Point::~Point(){
    Point::InstanceCount--;
}
Point::Point(const Point &other){
    _x = other._x;
    _y = other._y;
    Point::InstanceCount++;
}
float Point::CalcDistanceTo(const Point *other) const{
    float dx = this -> _x - other -> _x;
    float dy = this -> _y - other -> _y;
    return sqrt(dx * dx + dy * dy);
}

float Point::CalcDistance(const Point *a, const Point *b){
    return a -> CalcDistanceTo(b);
}