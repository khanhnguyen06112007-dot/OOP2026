#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "DynamicArray.h"
#include <iostream>

using namespace std;

int Point::InstanceCount = 0;
int Line::InstanceCount = 0;
int Rectangle::InstanceCount = 0;
int DynamicArray::InstanceCount = 0;

int main(){
    std::cout << "==============================\n";
    Point p;
    std::cin >> p;
    std::cout << p;

    std::cout << "==============================\n";
    Line l;
    std::cin >> l;
    std::cout << l;

    std::cout << "==============================\n";
    Rectangle r;
    std::cin >> r;
    std::cout << r;

    std::cout << "==============================\n";
    DynamicArray arr;
    std::cin >> arr;
    std::cout << arr;
    return 0;
}