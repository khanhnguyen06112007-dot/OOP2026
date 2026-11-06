#include "Rectangle.h"

Point* Rectangle::TopLeft() const{
    return _topLeft;
}

Point* Rectangle::BottomRight() const{
    return _bottomRight;
}
Rectangle::Rectangle() {
    this->_topLeft = new Point(0, 0);
    this->_bottomRight = new Point(1, 1);
    Rectangle::InstanceCount++;
}

Rectangle::Rectangle(const Point* tl, const Point* br) {
    if (tl == nullptr || br == nullptr) {
        Rectangle();
    }
    else{
        this->_topLeft = new Point(*tl);
        this->_bottomRight = new Point(*br);
    }
    Rectangle::InstanceCount++;
}

Rectangle::Rectangle(const Rectangle& other) {
    if (other._topLeft == nullptr || other._bottomRight == nullptr) {
        Rectangle();
    }
    else{
        this->_topLeft = new Point(*(other._topLeft));
        this->_bottomRight = new Point(*(other._bottomRight));
    }
    Rectangle::InstanceCount++;
}

Rectangle::~Rectangle() {
    if (_topLeft){
        _topLeft -> SetX(0);
        _topLeft -> SetY(0);
    }
    if (_bottomRight){
        _bottomRight -> SetX(0);
        _bottomRight -> SetY(0);
    }
    delete this->_topLeft;
    delete this->_bottomRight;
    _topLeft = nullptr;
    _bottomRight = nullptr;
    Rectangle::InstanceCount--;
}

bool Rectangle::SetTopLeft(const Point* value) {
    if (value == nullptr) {
        return false;
    }
    if (value -> X() >= _bottomRight -> X() || value -> Y() <= _bottomRight -> Y()){
        return false;
    }
    if (_topLeft != nullptr) delete _topLeft;
    this->_topLeft = new Point(*value);
    return true;
}

bool Rectangle::SetBottomRight(const Point* value) {
    if (value == nullptr) {
        return false;
    }
    if (value -> X() <= _topLeft -> X() || value -> Y() >= _topLeft -> Y()){
        return false;
    }
    if (this->_bottomRight != nullptr) {
        delete this->_bottomRight;
    }
    this->_bottomRight = new Point(*value);
    return true;
}

float Rectangle::Width() const {
    if (this->_topLeft == nullptr || this->_bottomRight == nullptr) {
        return 0.0;
    }
    return std::abs(this->_bottomRight->X() - this->_topLeft->X());
}

float Rectangle::Height() const {
    if (this->_topLeft == nullptr || this->_bottomRight == nullptr) {
        return 0.0;
    }
    return std::abs(this->_bottomRight->Y() - this->_topLeft->Y());
}

float Rectangle::Perimeter() const {
    return 2 * (this->Width() + this->Height());
}

float Rectangle::Area() const {
    return this->Width() * this->Height();
}

std::string Rectangle::ToString() const{
    std::string res = "Top Left: " + this->_topLeft->ToString() + ", Bottom Right: " + this->_bottomRight->ToString();
    double width = this->Width();
    double height = this->Height();
    double perimeter = this->Perimeter();
    double area = this->Area();
    res += ", Width: " + std::to_string(width) + ", Height: " + std::to_string(height) 
        + ", Perimeter: " + std::to_string(perimeter) + ", Area: " + std::to_string(area);
    return res;
}
std::istream& operator >> (std::istream &in, Rectangle &r){
    std::cout << "Moi thay nhap thong tin hinh chu nhat: \n";
    std::cout << "Moi thay nhap diem tren ben trai: \n";
    in >> *r._topLeft;
    std::cout << "Moi thay nhap diem duoi ben phai: \n";
    in >> *r._bottomRight;
    return in;
}
std::ostream& operator << (std::ostream &out, const Rectangle& r){
    out << r.ToString() << "\n";
    return out;
}