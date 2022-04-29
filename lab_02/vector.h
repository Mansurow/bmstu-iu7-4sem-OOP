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
#include "errors.h"

#define EPS 1e-8

using namespace std;

template<typename Type>
class Vector: public BaseVector
{
public:
    friend class Iterator<Type>;

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

    double getLength() const;
    int getSize() const noexcept override;
    bool isEmpty() const noexcept override;

    bool isZero() const; // проверка на нулевой вектор
    bool isSingle() const; // проверка единичный вектор

    bool isCollinear(const Vector<Type>&) const;
    bool isOrthgonal(const Vector<Type> &) const;

    Vector<Type> getSingle() const; // нормированием вектора

    // Сумма двух векторов
    Vector<Type> operator +(const Vector<Type> &) const;
    Vector<Type> &operator +=(const Vector<Type> &);
    Vector<Type> &sum(const Vector<Type> &);

    // Разность двух векторов
    Vector<Type> &operator -=(const Vector<Type> &);
    Vector<Type> operator -(const Vector<Type> &) const;
    Vector<Type> operator -();
    Vector<Type> &sub(const Vector<Type> &);

    // Умножение на число
    Vector<Type> operator *(const Type &number) const;
    Vector<Type> &operator *=(const Type &number);
    Vector<Type> &mul(const Type &number);

    // Скалярное произведение
    Type operator *(const Vector<Type> &) const;
    Type operator *=(const Vector<Type> &);
    Type scalarMul(const Vector<Type> &) const;

    // Векторное произведение
    Vector<Type> operator &(const Vector<Type> &) const;
    Vector<Type> &operator &=(const Vector<Type> &);
    Vector<Type> &vectorMul(const Vector<Type> &);

    // Деление вектора на число
    Vector<Type> &operator /=(const Type& number);
    Vector<Type> operator /(const Type& number) const;
    Vector<Type> &div(const Type& number);

    // Логические операции
    bool operator ==(const Vector<Type> &) const;
    bool operator !=(const Vector<Type> &) const;

    double angleBetweenVectors(const Vector<Type>&) const;

    Iterator<Type> begin() noexcept;
    Iterator<Type> end() noexcept;

protected:
    Type sumValue();
    void vecSum(Vector<Type> &res, const Vector<Type> &fV, const Vector<Type> &sV) const;
    void vecSub(Vector<Type> &res, const Vector<Type> &fV, const Vector<Type> &sV) const;
    void vecMul(Vector<Type> &res, const Vector<Type> &fV, const Vector<Type> &sV) const;

    void allocNewVectorMem(int amount);
private:
    shared_ptr<Type> values;
};

// создан для быстрого вывода вектора
template<typename Type>
ostream& operator <<(ostream& os, const Vector<Type>& vec)
{
    Iterator<Type> iter(vec);

    if (!iter)
    {
        os << "Vector is empty.";
        return os;
    }

    os << '(' << *iter;
    for (iter++; iter; iter++)
        os << ", " << *iter ;
    os << ')';

    return os;
}

#endif // VECTOR_H
