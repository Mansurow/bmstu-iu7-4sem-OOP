#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H

#include <iostream>

class BaseIterator
{
public:
    BaseIterator();
    explicit BaseIterator(const BaseIterator &);
    virtual ~BaseIterator() = 0;
protected:
    int index;
    int size;
};

BaseIterator::BaseIterator()
{
    index = 0;
    size = 0;
};

BaseIterator::BaseIterator(const BaseIterator& iterator)
{
    index = iterator.index;
    size = iterator.size;
};

BaseIterator::~BaseIterator() {}

#endif // BASE_ITERATOR_H
