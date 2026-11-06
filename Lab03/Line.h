#ifndef LINE_H
#define LINE_H
#include "Point.h"
#include <stdexcept>
class Line{
private:
    Point *_start;
    Point *_end;
public:
    static int InstanceCount;
    double Length() const;

    Point* getStart() const;
    Point* getEnd() const;
    void SetStart(const Point *value);
    void SetEnd(const Point *value);

    Line();
    Line(const Point *a, const Point *b);
    Line(const Line &other);
    ~Line();
};

#endif