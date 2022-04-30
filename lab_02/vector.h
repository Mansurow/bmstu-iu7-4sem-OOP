#ifndef VECTOR_H
#define VECTOR_H

#include <stdarg.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <stdexcept>

#include "base_vector.h"
#include "iterator.hpp"
#include "const_iterator.h"
#include "errors.h"

#define EPS 1e-8

using namespace std;
// на каждый оператор сделать метод с соотвествующим название
// умножение элементов вектора
// умножение двух элементов вектора
// так же с суммой
template<typename Type>
class Vector: public BaseVector
{
public:
    friend class Iterator<Type>;
    friend class ConstIterator<Type>;

    Vector();
    explicit Vector(int len);
    Vector(int len, Type* array);
    Vector(int len, Type vector, ...);
    Vector(initializer_list<Type> args);
    explicit Vector(const Vector<Type> &vector);
    Vector(Vector<Type>&& vector);

    virtual ~Vector();

    Vector<Type> &operator =(const Vector<Type> &vector);
    Vector<Type> &operator =(initializer_list<Type> args);
    Vector<Type> &operator =(Vector<Type> &&vector);

    bool setItem (int index, const Type &item);
          Type &getItem(int index);
    const Type &getItem(int index) const;

          Type &operator [](int index);
    const Type &operator [](int index) const;

    Type getLength() const;
    int getSize() const noexcept override;
    bool isEmpty() const noexcept override;

    bool isZero() const; // проверка на нулевой вектор
    bool isSingle() const; // проверка единичный вектор

    bool isCollinear(const Vector<Type>&) const;
    bool isOrthgonal(const Vector<Type> &) const;

    Vector<Type> getSingle() const; // нормированием вектора

    // Сумма двух векторов - DONE
    template<typename U>
    decltype(auto) operator +(const Vector<U> &) const;
     Vector<Type> &operator +=(const Vector<Type> &);
    template<typename U>
    decltype(auto) sum(const Vector<U> &) const;
     Vector<Type> &sumEqual(const Vector<Type> &);

    // Разность двух векторов - Done
    template<typename U>
    decltype(auto) operator -(const Vector<U> &) const;
     Vector<Type> &operator -=(const Vector<Type> &);
    template<typename U>
    decltype(auto) sub(const Vector<U> &) const;
     Vector<Type> &subEqual(const Vector<Type> &);
    Vector<Type> operator -();
    Vector<Type> reverse();

    // Умножение на число - Done
    template<typename U>
    decltype(auto) operator *(const U &number) const;
    Vector<Type> &operator *=(const Type &number);
    template<typename U>
    decltype(auto) mulNum(const U &number) const;
    Vector<Type> &mulNumEqual(const Type &number);

    //Умножение элементов двух веткоров - DONE
    template<typename U>
    decltype(auto) operator ^(const Vector<U> &) const;
    Vector<Type> &operator ^=(const Vector<Type>&);
    template<typename U>
    decltype(auto) mulElems(const Vector<U> &) const;
    Vector<Type>  &mulElemsEqual(const Vector<Type> &);

    // Скалярное произведение
    template<typename U>
    decltype(auto) operator *(const Vector<U> &) const;
             Type &operator *=(const Vector<Type> &);
    template<typename U>
    decltype(auto) scalarMul(const Vector<U> &) const;
             Type &scalarMulEqual(const Vector<Type> &);

    // Векторное произведение - Done
    template<typename U>
    decltype(auto) operator &(const Vector<U> &) const;
     Vector<Type> &operator &=(const Vector<Type> &);
    template<typename U>
    decltype(auto) vectorMul(const Vector<U> &) const;
     Vector<Type> &vectorMulEqual(const Vector<Type> &);

    // Деление вектора на число - Done
    template<typename U>
    decltype(auto) operator /(const U& number) const;
     Vector<Type> &operator /=(const Type& number);
    template<typename U>
    decltype(auto) divNum(const U& number) const;
     Vector<Type> &divNumEqual(const Type& number);

    // Логические операции
    bool operator ==(const Vector<Type> &) const;
    bool operator !=(const Vector<Type> &) const;

    double angleBetweenVectors(const Vector<Type>&) const;

    Iterator<Type> begin() noexcept;
    Iterator<Type> end() noexcept;

    ConstIterator<Type> begin() const noexcept;
    ConstIterator<Type> end() const noexcept;
    ConstIterator<Type> cbegin() const noexcept;
    ConstIterator<Type> cend() const noexcept;

protected:
    Type sumValue();
    void vecSum(Vector<Type> &res, const Vector<Type> &fV, const Vector<Type> &sV) const;
    void vecSub(Vector<Type> &res, const Vector<Type> &fV, const Vector<Type> &sV) const;
    void vecMul(Vector<Type> &res, const Vector<Type> &fV, const Vector<Type> &sV) const;

    void allocNewVectorMem(int amount);
private:
    shared_ptr<Type[]> values; // Type[] - передача болле сложных типов (классов, объектов)
};

// создан для быстрого вывода вектора
template<typename Type>
ostream& operator <<(ostream& os, const Vector<Type>& vec)
{
    Iterator<Type> iter(vec);
    os << '(';
    for (; iter; iter++)
        if (iter + 1)
            os << *iter <<  ", ";
        else
            os << *iter;
    os << ')';

    return os;
}

#endif // VECTOR_H
