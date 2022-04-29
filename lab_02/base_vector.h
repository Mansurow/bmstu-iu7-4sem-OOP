#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H

#include<iostream>

class BaseVector
{
public:
    BaseVector();
    BaseVector(const BaseVector&);
    virtual ~BaseVector() = default;

    virtual bool isEmpty() const = 0;
    virtual int  getSize() const = 0;

protected:
    int size = 0;
};

BaseVector::BaseVector()
{
    size = 0;
}

BaseVector::BaseVector(const BaseVector& vector)
{
   size = vector.size;
}

#endif // BASE_VECTOR_H
