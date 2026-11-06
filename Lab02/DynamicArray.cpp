#include "DynamicArray.h"
int DynamicArray::Length() const{
    return _len;
}
DynamicArray::DynamicArray() {
    this->_a = nullptr;
    this->_len = 0;
    DynamicArray::InstanceCount++;
}

DynamicArray::DynamicArray(int len) {
    if (len < 0) {
        throw std::invalid_argument("Loi: Do dai mang khong duoc am!");
    }
    this->_len = len;
    if (this->_len > 0) {
        this->_a = new int[this->_len];
        for (int i = 0; i < _len; i++){
            _a[i] = 0;
        }
    } else {
        this->_a = nullptr;
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
        throw std::out_of_range("Loi: Chi so truy cap nam ngoai pham vi mang!");
    }
    return this->_a[i];
}

void DynamicArray::SetAt(int i, int value) {
    if (i < 0 || i >= this->_len) {
        throw std::out_of_range("Loi: Chi so truy cap nam ngoai pham vi mang!");
    }
    this->_a[i] = value;
}