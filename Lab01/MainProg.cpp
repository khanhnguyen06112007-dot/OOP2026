#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "DynamicArr.h"
int main(){
    //Demo Point
    Point *start = new Point(4, 3);
    Point *end = new Point(10, 9);
    float length = start -> CalcDistanceTo(end);
    std::cout << "Khoang cach 2 diem la: " << length << "\n";

    delete start;
    delete end;  
    std::cout << "================================\n";
    //Demo Circle 
    Circle c;
    Point *center = new Point(1, 2);
    c.SetCenter(center);
    c.SetRadius(2.5);
    std::cout << "Center point: (" << c.Center()->X() << ", " << c.Center()->Y() << ")\n";
    std::cout << "Ban kinh = " << c.Radius() << "\n";
    std::cout << "Duong Kinh = " << c.Diameter() << "\n";
    std::cout << "Chu vi = " << c.Perimeter() << "\n";
    std::cout << "Dien tich = " << c.Area() << "\n";
    std::cout << "==================================\n";
    //Demo dynamic array
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    DynamicArray a(arr, size);
    a.printArray();
    a.PushBack(6);
    a.PushBack(7);

    std::cout << "Array a sau khi them vao sau mang la: \n";
    a.printArray();

    try{
        std::cout << "Moi thay nhap index: ";
        int index;
        std::cin >> index;
        std::cout << "Phan tu tai index = " << index << " la: ";
        std::cout << a.getAt(index) << "\n";
    }catch(const std::out_of_range &error){
        std::cout << "Error: " << error.what() << "\n";
    }
    return 0;
}