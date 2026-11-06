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
    //Demo Point
    cout << "===============================================================\n";
    Point *start = new Point(4, 3);
    Point *end = new Point(10, 9);
    float length = Point::CalcDistance(start, end);
    cout << "Khoang cach 2 diem la: " << length << endl;

    Point root(5, 6);
    Point copy(root);
    cout << "Nut copy: " << copy.X() << " " << copy.Y() << endl;
    cout << "So diem da tao ra la: " << Point::InstanceCount << endl;
    delete start;
    delete end;

    //Demo line
    cout << "===============================================================\n";
    Point* p1 = new Point(4, 3);
    Point* p2 = new Point(10, 9);
    Line* line1 = new Line(p1, p2);

    cout << "Do dai line 1: " << line1 -> Length() << endl;

    Line line2(*line1);
    cout << "Do dai line 2 khi copy line 1 la: " << line2.Length() << endl;
    Point *s = new Point(1, 2);
    Point *e = new Point(2, 3);
    line2.SetStart(s);
    line2.SetEnd(e);
    cout << "Do dai line 2 sau khi thay doi diem start va end: " << line2.Length() << endl;
    cout << "So doan thang duoc tao ra la: " << Line::InstanceCount << endl;
    delete p1;
    delete p2;
    delete s;
    delete e;

    //Demo Rectangle
    cout << "===============================================================\n";
    Point* p3 = new Point(2, 8);
    Point* p4 = new Point(10, 3);
    Rectangle* rect1 = new Rectangle(p3, p4);
    cout << "HCN 1 - Rong: " << rect1->Width() 
             << ", Cao: " << rect1->Height() 
             << ", Dien tich: " << rect1->Area() 
             << ", Chu vi: " << rect1 -> Perimeter() << endl;
    Rectangle rect2(*rect1);
    cout << "Hinh chu nhat 2 duoc sao chep tu hinh chu nhat 1: \n";
    cout << "HCN 2 - Rong: " << rect2.Width() 
             << ", Cao: " << rect2.Height() 
             << ", Dien tich: " << rect2.Area() 
             << ", Chu vi: " << rect1 -> Perimeter() << endl;
    Point *topleft = new Point(7, 8);
    Point *bottomRight = new Point(10, 1);
    rect2.SetTopLeft(topleft);
    rect2.SetBottomRight(bottomRight);
    cout << "Hinh chu nhat 2 sau khi thay doi gia tri topleft va bottomRight\n";
    cout << "HCN 2 - Rong: " << rect2.Width() 
             << ", Cao: " << rect2.Height() 
             << ", Dien tich: " << rect2.Area() 
             << ", Chu vi: " << rect1 -> Perimeter() << endl;
    cout << "So luong hinh chu nhat duoc tao ra la: " << Rectangle::InstanceCount << "\n";
    delete p3;
    delete p4;
    delete topleft;
    delete bottomRight;

    //Demo DynamicArray
    cout << "===============================================================\n";
    DynamicArray arr1;
    arr1.PushBack(10);
    arr1.PushBack(20);
    arr1.PushBack(30);

    cout << "Mang arr1 (len = " << arr1.Length() << "): ";
    for (int i = 0; i < arr1.Length(); i++) {
        cout << arr1.GetAt(i) << " ";
    }
    cout << endl;

    //Gọi hàm tạo sao chép 
    DynamicArray arr2(arr1);
    arr2.PushBack(40);
    arr2.SetAt(0, 999);

    cout << "Mang arr2 sau khi sua va them (len = " << arr2.Length() << "): ";
    for (int i = 0; i < arr2.Length(); i++) {
        cout << arr2.GetAt(i) << " ";
    }
    cout << endl;
    cout << "So luong Dynamic Array duoc tao ra la: " << DynamicArray::InstanceCount << "\n";
    return 0;
}