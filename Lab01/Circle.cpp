#include "Circle.h"
#include "Point.h"
#include <stdexcept>
Point* Circle::Center(){
    return _center;
}

float Circle::Radius(){
    return _radius;
}
void Circle::SetCenter(Point *value){
    if (value == nullptr){
        throw std::invalid_argument("Con tro khong duoc null");
    }
    _center = value;
}
void Circle::SetRadius(float value){
    if (value <= 0){
        throw std::out_of_range("Ban kinh phai lon hon 0");
    }
    _radius = value;
}
    
float Circle::Diameter(){
    return 2 * _radius;
}
float Circle::Perimeter(){
    return 2 * PI * _radius;
}
float Circle::Area(){
    return PI * _radius * _radius;
}

Circle::Circle(){
    _center = new Point();
}

Circle::~Circle(){
    delete _center;
}