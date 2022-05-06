#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H

class BaseVector
{
public:
    virtual ~BaseVector() = default;

    virtual bool isEmpty() const = 0;
    virtual int  getSize() const = 0;

protected:
    int size = 0;
};

#endif // BASE_VECTOR_H
