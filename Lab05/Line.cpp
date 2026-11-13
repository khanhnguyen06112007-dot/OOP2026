#include "Line.h"
#include "Point.h"
double Line::Length() const{
    if (this -> _start == nullptr || this -> _end == nullptr){
        return 0.0;
    }
    return Point::CalcDistance(_start, _end);
}

Point* Line::getStart() const{
    return _start;
}

Point* Line::getEnd() const{
    return _end;
}

bool Line::SetStart(const Point *value){
    if (value == nullptr || this -> _start == nullptr){
        return false;
    }
    _start = new Point(*value);
    return true;
}

bool Line::SetEnd(const Point *value){
    if (value == nullptr || this -> _end == nullptr){
        return false;
    }
    _end = new Point(*value);
    return true;
}

Line::Line(){
    _start = new Point(0, 0);
    _end = new Point(0, 0);
    Line::InstanceCount++;
}

Line::Line(const Point *a, const Point *b){
    if (a == nullptr || b == nullptr){
        Line();
    }
    else{
        this -> _start = new Point(*a);
        this -> _end = new Point(*b);
    }
    Line::InstanceCount++;
}

Line::Line(const Line &other){
    this -> _start = new Point(*other._start);
    this -> _end = new Point(*other._end);
    Line::InstanceCount++;
}
Line::~Line(){
    if (_start){
        _start -> SetX(0);
        _start -> SetY(0);
    }
    if (_end){
        _end -> SetX(0);
        _start -> SetY(0);
    }
    delete _start;
    delete _end;
    _start = nullptr;
    _end = nullptr;
    Line::InstanceCount--;
}
std::string Line::ToString() const{
    std::string res = "Line: Start = " + _start -> ToString() + ", End = " + _end -> ToString();
    double len = Length();
    res += ", Length = " + std::to_string(len);
    return res;
}
std::istream& operator >> (std::istream &in, Line& l){
    std::cout << "Moi thay nhap thong tin doan thang: \n";
    std::cout << "Moi thay nhap diem bat dau: \n";
    in >> *l._start;
    std::cout << "Moi thay nhap diem ket thuc: \n";
    in >> *l._end;
    return in;
}
std::ostream& operator << (std::ostream &out, const Line& l){
    out << l.ToString() << "\n";
    return out;
}
Line* Line::Parse(std::string s){
    std::vector<std::string> res = Tokenizer::Parse(s);
    std::vector<float> nums;
    for (std::string i : res){
        nums.push_back(stof(i));
    }
    Point *start = new Point(nums[0], nums[1]);
    Point *end = new Point(nums[2], nums[3]);
    Line *r = new Line(start, end);
    return r;
}