#include "Line.h"

double Line::Length() const{
    if (this -> _start == nullptr || this -> _end == nullptr){
        return 0.0;
    }
    return Point::CalcDistance(_start, _end);
}

Point* Line::getStart() const{
    return _start;
}

Point* Line::getEnd() const{
    return _end;
}

bool Line::SetStart(const Point *value){
    if (value == nullptr || this -> _start == nullptr){
        return false;
    }
    _start = new Point(*value);
}

bool Line::SetEnd(const Point *value){
    if (value == nullptr || this -> _end == nullptr){
        return false;
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
        Line();
    }
    else{
        this -> _start = new Point(*a);
        this -> _end = new Point(*b);
    }
    Line::InstanceCount++;
}

Line::Line(const Line &other){
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
std::string Line::ToString() const{
    
}
    friend std::istream& operator >> (std::istream &in, Line& l);
    friend std::ostream& operator << (std::ostream &out, const Line& l);