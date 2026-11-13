#include "DynamicArray.h"
#include "Tokenizer.h"
#include <string>
#include <iostream>
int DynamicArray::Length() const{
    return _len;
}
DynamicArray::DynamicArray() {
    this->_a = nullptr;
    this->_len = 0;
    DynamicArray::InstanceCount++;
}

DynamicArray::DynamicArray(int len) {
    if (len <= 0) {
        DynamicArray();
    }
    else{
        this->_len = len;
        this->_a = new int[this->_len];
        for (int i = 0; i < _len; i++){
            _a[i] = 0;
        }
    }
    DynamicArray::InstanceCount++;
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    this->_len = other._len;
    if (other._a != nullptr && this->_len > 0) {
        this->_a = new int[this->_len];
        for (int i = 0; i < this->_len; i++) {
            this->_a[i] = other._a[i];
        }
    } else {
        this->_a = nullptr;
    }
    DynamicArray::InstanceCount++;
}

DynamicArray::~DynamicArray() {
    if (this->_a != nullptr) {
        for (int i = 0; i < _len; i++){
            _a[i] = 0;
        }
        delete[]_a;
        _len = 0;
        _a = nullptr;
    }
}

void DynamicArray::PushBack(int value) {
    int newLen = this->_len + 1;
    int* temp = new int[newLen];

    for (int i = 0; i < this->_len; i++) {
        temp[i] = this->_a[i];
    }

    temp[this->_len] = value;

    if (this->_a != nullptr) {
        delete[] this->_a;
    }
    this->_a = temp;
    this->_len = newLen;
}

int DynamicArray::GetAt(int i) const {
    if (i < 0 || i >= this->_len) {
        return -1;
    }
    return this->_a[i];
}

void DynamicArray::SetAt(int i, int value) {
    if (i < 0 || i >= this->_len) {
        return;
    }
    this->_a[i] = value;
}

std::string DynamicArray::ToString() const{
    std::string result = "len = " + std::to_string(this->_len) + ", a = ";
    result += "[";
    for (int i = 0; i < this->_len; i++) {
        result += std::to_string(this->_a[i]);
        if (i < this->_len - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}
std::istream& operator >> (std::istream &in, DynamicArray &arr){
    while(true){
        std::cout << "Nhap vao so luong phan tu cua mang: ";
        in >> arr._len;
        if (arr._len < 0) {
            std::cout << "So luong phan tu phai lon hon hoac bang 0. Vui long nhap lai." << std::endl;
        } else {
            break;
        }
    }
    if (arr._a != nullptr) {
        delete[] arr._a;
    }
    if (arr._len > 0) {
        arr._a = new int[arr._len];
        for (int i = 0; i < arr._len; i++) {
            std::cout << "Nhap vao phan tu thu " << i << ": ";
            in >> arr._a[i];
        }
    } else {
        arr._a = nullptr;
    }
    return in;
}
std::ostream& operator << (std::ostream &out, const DynamicArray& arr){
    out << arr.ToString() << "\n";
    return out;
}
DynamicArray* DynamicArray::Parse(std::string s){
    std::vector<std::string> res = Tokenizer::Parse(s);
    std::vector<int> num;
    for (std::string i : res){
        num.push_back(stoi(i));
    }
    DynamicArray *a = new DynamicArray(num.size());
    for (int i = 0; i < num.size(); i++){
        a -> _a[i] = num[i];
    }
    return a;
}