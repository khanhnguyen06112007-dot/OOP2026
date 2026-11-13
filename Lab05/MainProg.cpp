#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "DynamicArray.h"
#include <iostream>
#include "Tokenizer.h"
#include <vector>
#include <string>
using namespace std;

int Point::InstanceCount = 0;
int Line::InstanceCount = 0;
int Rectangle::InstanceCount = 0;
int DynamicArray::InstanceCount = 0;

int main(){
    std::string string_for_point = "41, 10";
    Point *p = Point::Parse(string_for_point);
    std::cout << *p << "\n";

    std::string string_for_line = "(3, 4), (5, 9)";
    Line *l = Line::Parse(string_for_line);
    std::cout << *l << "\n";

    std::string string_for_rectangle = "(6, 15), (1, 20)";
    Rectangle *r = Rectangle::Parse(string_for_rectangle);
    std::cout << *r << "\n";

    std::string string_for_dynamic_array = "5, 8, 12, 15, 612, 19";
    DynamicArray* a = DynamicArray::Parse(string_for_dynamic_array);
    std::cout << *a << "\n";
    
    return 0;
}