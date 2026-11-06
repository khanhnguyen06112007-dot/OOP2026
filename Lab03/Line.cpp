#include "Line.h"

double Line::Length() const{
    if (this -> _start == nullptr || this -> _end == nullptr){
        throw std::invalid_argument("con tro bi nullptr");
    }
    return Point::CalcDistance(_start, _end);
}

Point* Line::getStart() const{
    return _start;
}

Point* Line::getEnd() const{
    return _end;
}

void Line::SetStart(const Point *value){
    if (value == nullptr){
        throw std::invalid_argument("Con tro bi nullptr");
    }
    if (this -> _start == nullptr){
        delete _start;
    }
    _start = new Point(*value);
}

void Line::SetEnd(const Point *value){
    if (value == nullptr){
        throw std::invalid_argument("Con tro bi nullptr");
    }
    if (this -> _end == nullptr){
        delete _end;
    }
    _end = new Point(*value);
}

Line::Line(){
    _start = new Point(0, 0);
    _end = new Point(0, 0);
    Line::InstanceCount++;
}

Line::Line(const Point *a, const Point *b){
    if (a == nullptr || b == nullptr){
        throw std::invalid_argument("Con tro bi nullptr");
    }
    this -> _start = new Point(*a);
    this -> _end = new Point(*b);
    Line::InstanceCount++;
}

Line::Line(const Line &other){
    if (other._start == nullptr || other._end == nullptr){
        throw std::invalid_argument("Con tro bi nullptr");
    }
    this -> _start = new Point(*other._start);
    this -> _end = new Point(*other._end);
    Line::InstanceCount++;
}
Line::~Line(){
    if (_start){
        _start -> SetX(0);
        _start -> SetY(0);
    }
    if (_end){
        _end -> SetX(0);
        _start -> SetY(0);
    }
    delete _start;
    delete _end;
    _start = nullptr;
    _end = nullptr;
    Line::InstanceCount--;
}