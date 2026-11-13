#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"
#include <stdexcept>
#include "Tokenizer.h"
#include <string>
class Rectangle{
private:
    Point *_topLeft;
    Point *_bottomRight;
public:
    static int InstanceCount;

    Point* TopLeft() const;
    Point* BottomRight() const;
    bool SetTopLeft(const Point* value);
    bool SetBottomRight(const Point* value);
public:
    float Width() const;
    float Height() const;
    float Perimeter() const;
    float Area() const;
    Rectangle();
    Rectangle(const Point* tl, const Point* br);
    Rectangle(const Rectangle& other); 
    ~Rectangle();
public:
    std::string ToString() const;
    friend std::istream& operator >> (std::istream &in, Rectangle &r);
    friend std::ostream& operator << (std::ostream &out, const Rectangle& r);
public:
    static Rectangle* Parse(std::string s);
};
#endif