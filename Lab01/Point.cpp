#include "Point.h"

float Point::X(){
    return _x;
}
float Point::Y(){
    return _y;
}
void Point::SetX(float value){
    _x = value;
}
void Point::SetY(float value){
    _y = value;
}
Point::Point(){
    _x = _y = 0;
}
Point::Point(float x, float y){
    _x = x;
    _y = y;
}
Point::~Point(){}
float Point::CalcDistanceTo(const Point *other){
    float dx = (this -> _x) - (other -> _x);
    float dy = (this -> _y) - (other -> _y);
    return sqrt(dx * dx + dy * dy);
}