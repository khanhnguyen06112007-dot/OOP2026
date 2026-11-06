#ifndef DYNAMICARR_H
#define DYNAMICARR_H
#pragma once
class DynamicArray{
private:
    int *_a;
    int _len;
public:
    DynamicArray();
    DynamicArray(int *arr, int len);
    ~DynamicArray();
    
    void printArray();
    void PushBack(int value);
    int getAt(int index);
};
#endif