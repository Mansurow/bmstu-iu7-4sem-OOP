#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H

#include <iostream>

class BaseIterator
{
public:
    virtual ~BaseIterator() = 0;
protected:
    int index;
    int size;
};

BaseIterator::~BaseIterator() {}

#endif // BASE_ITERATOR_H
