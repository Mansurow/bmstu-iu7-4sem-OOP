#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <iostream>
#include <ctime>

#include "base_iterator.h"
#include "errors.h"

template<typename Type>
class Vector;

template<typename Type>
class Iterator: public BaseIterator
{
public:
   Iterator();
   Iterator(const Iterator<Type>&);
   Iterator(const Vector<Type>&);

         Type& operator *();
   const Type& operator *() const;
         Type* operator ->();
   const Type* operator ->() const;
   operator bool() const;

         Type &operator [](int index);
   const Type &operator [](int index) const;

   Iterator<Type>& operator =(const Iterator<Type>& iterator);

   Iterator<Type>& operator +=(int number);
   Iterator<Type>& operator ++();     // префиксный инкремент
   Iterator<Type>  operator ++(int);  // постфиксный инкремент
   Iterator<Type>  operator + (int number) const;

   Iterator<Type>& operator -=(int number);
   Iterator<Type>& operator --();    // префиксный декремент
   Iterator<Type>  operator --(int); // постфиксный декремент
   Iterator<Type>  operator - (int number) const;

   bool operator <=(const Iterator<Type>& iterator) const;
   bool operator <(const Iterator<Type>& iterator) const;
   bool operator >=(const Iterator<Type>& iterator) const;
   bool operator >(const Iterator<Type>& iterator) const;
   bool operator ==(const Iterator<Type>& iterator) const;
   bool operator !=(const Iterator<Type>& iterator) const;
 // []
protected:
    Type* get_cur_ptr() const;

    void check_object(int) const;   // проверка объекта на null
    void check_validity(int) const; // проверака

private:
    std::weak_ptr<Type[]> weakPtr;
};

#endif // ITERATOR_H
