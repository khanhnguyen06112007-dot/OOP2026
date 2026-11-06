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

std::string Point::ToString() const{
    std::string res = "(" + std::to_string(_x) + "," + std::to_string(_y) + ")";
    return res;
}
std::istream& operator >> (std::istream &in, Point &p){
    float num;
    while(true){
        std::cout << "Moi thay nhap hoanh do x = ";
        if (in >> num){
            p.SetX(num);
            break;
        }
        else{
            std::cout << "Hoanh do x khong hop le! \n";
            in.clear();
            in.ignore();
        }
    }
    
    while(true){
        std::cout << "Moi thay nhap tung do y = ";
        if (in >> num){
            p.SetY(num);
            break;
        }
        else{
            std::cout << "Tung do y khong hop le! \n";
            in.clear();
            in.ignore();
        }
    }
    return in;
}
std::ostream& operator << (std::ostream &out, const Point& p){
    out << "Point: " << " " << p.ToString() << "\n";
    return out;
}