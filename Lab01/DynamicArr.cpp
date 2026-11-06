#include "DynamicArr.h"
#include <stdexcept>
#include <iostream>
DynamicArray::DynamicArray(){
    _a = nullptr;
    _len = 0;
}
DynamicArray::DynamicArray(int *arr, int len){
    if (len == 0){
        DynamicArray();
    }
    else{
        _len = len;
        _a = new int[_len];
        for (int i = 0; i < _len; i++){
            _a[i] = arr[i];
        }
    }
}
DynamicArray::~DynamicArray(){
    delete []_a;
}
void DynamicArray::printArray(){
    if (_len == 0){
        std::cout << "Array is empty! \n";
        return;
    }
    std::cout << "Size: " << _len << "\n";
    std::cout << "Element in array: ";
    for (int i = 0; i < _len; i++){
        std::cout << _a[i] << " ";
    } 
    std::cout << "\n";
}   
void DynamicArray::PushBack(int value) {        
    int *new_a = new int[_len + 1];
    for (int i = 0; i < _len; i++) {
        new_a[i] = _a[i];
    }
    delete[] _a;
    _a = new_a;
    _a[_len] = value;
    _len++;
}
int DynamicArray::getAt(int index){
    if (index < 0 || index >= _len){
        throw std::out_of_range("index nam ngoai kich thuoc mang");
    }
    return _a[index];
}