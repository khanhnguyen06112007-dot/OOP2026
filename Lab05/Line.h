#ifndef LINE_H
#define LINE_H
#include "Point.h"
#include "Tokenizer.h"
#include <stdexcept>
#include <string>
#include <iostream>
class Line{
private:
    Point *_start;
    Point *_end;
public:
    static int InstanceCount;
    double Length() const;
public:
    Point* getStart() const;
    Point* getEnd() const;
    bool SetStart(const Point *value);
    bool SetEnd(const Point *value);
public:
    Line();
    Line(const Point *a, const Point *b);
    Line(const Line &other);
    ~Line();
public:
    std::string ToString() const;
    friend std::istream& operator >> (std::istream &in, Line& l);
    friend std::ostream& operator << (std::ostream &out, const Line& l);
public:
    static Line* Parse(std::string s);
};
#endif