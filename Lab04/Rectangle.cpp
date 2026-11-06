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
        throw std::invalid_argument("Loi: Diem truyen vao khong duoc la nullptr!");
    }
    this->_topLeft = new Point(*tl);
    this->_bottomRight = new Point(*br);
    Rectangle::InstanceCount++;
}

Rectangle::Rectangle(const Rectangle& other) {
    if (other._topLeft == nullptr || other._bottomRight == nullptr) {
        throw std::invalid_argument("Loi: Hinh chu nhat chua diem nullptr!");
    }
    this->_topLeft = new Point(*(other._topLeft));
    this->_bottomRight = new Point(*(other._bottomRight));
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

void Rectangle::SetTopLeft(const Point* value) {
    if (value == nullptr) {
        throw std::invalid_argument("Loi: Diem topLeft moi khong duoc la nullptr!");
    }
    if (value -> X() >= _bottomRight -> X() || value -> Y() <= _bottomRight -> Y()){
        throw std::out_of_range("Vi tri topleft khong hop le!");
    }
    if (_topLeft != nullptr) delete _topLeft;
    this->_topLeft = new Point(*value);
}

void Rectangle::SetBottomRight(const Point* value) {
    if (value == nullptr) {
        throw std::invalid_argument("Loi: Diem bottomRight moi khong duoc la nullptr!");
    }
    if (value -> X() <= _topLeft -> X() || value -> Y() >= _topLeft -> Y()){
        throw std::out_of_range("Vi tri bottom right khong hop le!");
    }
    if (this->_bottomRight != nullptr) {
        delete this->_bottomRight;
    }
    this->_bottomRight = new Point(*value);
}

float Rectangle::Width() const {
    if (this->_topLeft == nullptr || this->_bottomRight == nullptr) {
        throw std::runtime_error("Loi: Toa do hinh chu nhat chua duoc khoi tao!");
    }
    return std::abs(this->_bottomRight->X() - this->_topLeft->X());
}

float Rectangle::Height() const {
    if (this->_topLeft == nullptr || this->_bottomRight == nullptr) {
        throw std::runtime_error("Loi: Toa do hinh chu nhat chua duoc khoi tao!");
    }
    return std::abs(this->_bottomRight->Y() - this->_topLeft->Y());
}

float Rectangle::Perimeter() const {
    return 2 * (this->Width() + this->Height());
}

float Rectangle::Area() const {
    return this->Width() * this->Height();
}