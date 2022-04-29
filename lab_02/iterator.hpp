#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator.h>

// конструктор копирования итератора
template<typename Type>
Iterator<Type>::Iterator(const Iterator<Type>& iterator)
{
    this->weakPtr = iterator.weakPtr;
    // определено в базовом классе
    //this->index = iterator.index;
    //this->size = iterator.size;
}

template<typename Type>
Iterator<Type>::Iterator(const Vector<Type>& vector)
{
    this->index = 0;
    this->size = vector.getSize();
    this->weakPtr = vector.values;
}

// операторы разыменования
template<typename Type>
Type& Iterator<Type>::operator *()
{
    check_object(__LINE__);
    check_validity(__LINE__);

    return *get_cur_ptr();
}

template<typename Type>
const Type& Iterator<Type>::operator *() const
{
    check_object(__LINE__);
    check_validity(__LINE__);

    return *get_cur_ptr();
}

template<typename Type>
Type* Iterator<Type>::operator ->()
{
    check_object(__LINE__);
    check_validity(__LINE__);

    return get_cur_ptr();
}

template<typename Type>
const Type* Iterator<Type>::operator ->() const
{
    check_object(__LINE__);
    check_validity(__LINE__);

    return get_cur_ptr();
}

// операция присваивания
template<typename Type>
Iterator<Type>& Iterator<Type>::operator =(const Iterator<Type>& iterator)
{
    iterator.check_object(__LINE__);

    weakPtr = iterator.weakPtr;
    index = iterator.index;
    size = iterator.size;

    return *this;
}

// операции сложения
template<typename Type>
Iterator<Type>& Iterator<Type>::operator +=(int number)
{
    check_object(__LINE__);
    index += number;

    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator +(int number) const
{
    check_object(__LINE__);
    Iterator<Type> iterator(*this);
    if (index + number <= size)
        iterator += number;

    return iterator;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator ++(int)
{
    check_object(__LINE__);
    if (index < size)
        ++(*this);

    return *this;
}

template<typename Type>
Iterator<Type>& Iterator<Type>::operator ++()
{
    check_object(__LINE__);
    if (index < size)
        ++index;

    return *this;
}

// операции вычитания
template<typename Type>
Iterator<Type>& Iterator<Type>::operator -=(int number)
{
    check_object(__LINE__);
    if (index >= number - 1)
        index -= number;

    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator -(int number) const
{
    check_object(__LINE__);

    Iterator<Type> iterator(*this);
    if (index >= number - 1)
        iterator -= number;

    return iterator;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator --(int)
{
    check_object(__LINE__);
    if (index >= 0)
        --(*this);

    return *this;
}

template<typename Type>
Iterator<Type>& Iterator<Type>::operator --()
{
    check_object(__LINE__);
    if (index >= 0)
        --index;

    return *this;
}

// логические операции
template<typename Type>
bool Iterator<Type>::operator <=(const Iterator<Type>& iterator) const
{
    check_object(__LINE__);

    return weakPtr <= iterator.weakPtr;
}

template<typename Type>
bool Iterator<Type>::operator <(const Iterator<Type>& iterator) const
{
    check_object(__LINE__);

    return weakPtr < iterator.weakPtr;
}

template<class Type>
bool Iterator<Type>::operator >=(const Iterator<Type>& iterator) const
{
    check_object(__LINE__);

    return weakPtr >= iterator.weakPtr;
}

template<typename Type>
bool Iterator<Type>::operator >(const Iterator<Type>& iterator) const
{
    check_object(__LINE__);

    return weakPtr > iterator.weakPtr;
}

template<typename Type>
bool Iterator<Type>::operator ==(const Iterator<Type>& iterator) const
{
    check_object(__LINE__);

    return weakPtr == iterator.weakPtr;
}

template<typename Type>
bool Iterator<Type>::operator !=(const Iterator<Type>& iterator) const
{
    check_object(__LINE__);

    return weakPtr != iterator.weakPtr;
}

template<typename Type>
Iterator<Type>::operator bool() const
{
    check_object(__LINE__);
    bool res = true;
    if (index >= size || index < 0 || size == 0)
        res = false;

    return res;
}

// проверки работы с объектом и итератором
template<typename Type>
void Iterator<Type>::check_object(int line) const
{
    if (weakPtr.expired())
    {
        time_t t_time = time(NULL);
        throw DeletedObject(__FILE__, typeid(*this).name(), line, ctime(&t_time));
    }
}

template<typename Type>
void Iterator<Type>::check_validity(int line) const {
    if (this->index >= this->size)
    {
        time_t currentTime = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), line, ctime(&currentTime));
    }
}

// достать текущий указатель на объект
template<typename Type>
Type* Iterator<Type>::get_cur_ptr() const
{
    std::shared_ptr<Type> copy_ptr = weakPtr.lock();
    return copy_ptr.get() + index;
}

#endif // ITERATOR_HPP
