#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <stdexcept>

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
};
#endif