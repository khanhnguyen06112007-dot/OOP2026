#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <stdexcept>
#include "Tokenizer.h"
#include <string>
#include <vector>
class DynamicArray {
public:
    static int InstanceCount;
private:
    int* _a;
    int _len;

public:
    int Length() const;

    void PushBack(int value);
    int GetAt(int i) const;
    void SetAt(int i, int value);
public:
    DynamicArray();
    DynamicArray(int len);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();
public:
    std::string ToString() const;
    friend std::istream& operator >> (std::istream &in, DynamicArray &arr);
    friend std::ostream& operator << (std::ostream &out, const DynamicArray& arr);
public:
    static DynamicArray* Parse(std::string s);
};
#endif