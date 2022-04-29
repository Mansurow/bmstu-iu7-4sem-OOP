#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

#include <const_iterator.h>

// конструктор копирования итератора
template<typename Type>
ConstIterator<Type>::ConstIterator(const ConstIterator<Type>& iterator)
{
    this->weakPtr = iterator.weakPtr;
    this->index = iterator.index;
    this->size = iterator.size;
}

template<typename Type>
ConstIterator<Type>::ConstIterator(const Vector<Type>& vector)
{
    this->index = 0;
    this->size = vector.getSize();
    this->weakPtr = vector.values;
}

// операторы разыменования
template<typename Type>
const Type& ConstIterator<Type>::operator *() const
{
    check_object(__LINE__);
    check_validity(__LINE__);

    return *get_cur_ptr();
}

template<typename Type>
const Type* ConstIterator<Type>::operator ->() const
{
    check_object(__LINE__);
    check_validity(__LINE__);

    return get_cur_ptr();
}

// операция присваивания
template<typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator =(const ConstIterator<Type>& iterator)
{
    iterator.check_object(__LINE__);

    weakPtr = iterator.weakPtr;
    index = iterator.index;
    size = iterator.size;

    return *this;
}

// операции сложения
template<typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator +=(int number)
{
    check_object(__LINE__);
    index += number;

    return *this;
}

template<typename Type>
ConstIterator<Type> ConstIterator<Type>::operator +(int number) const
{
    check_object(__LINE__);
    ConstIterator<Type> iterator(*this);
    if (index + number <= size)
        iterator += number;

    return iterator;
}

template<typename Type>
ConstIterator<Type> ConstIterator<Type>::operator ++(int)
{
    check_object(__LINE__);
    if (index < size)
        ++(*this);

    return *this;
}

template<typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator ++()
{
    check_object(__LINE__);
    if (index < size)
        ++index;

    return *this;
}

// операции вычитания
template<typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator -=(int number)
{
    check_object(__LINE__);
    if (index >= number - 1)
        index -= number;

    return *this;
}

template<typename Type>
ConstIterator<Type> ConstIterator<Type>::operator -(int number) const
{
    check_object(__LINE__);

    ConstIterator<Type> iterator(*this);
    if (index >= number - 1)
        iterator -= number;

    return iterator;
}

template<typename Type>
ConstIterator<Type> ConstIterator<Type>::operator --(int)
{
    check_object(__LINE__);
    if (index >= 0)
        --(*this);

    return *this;
}

template<typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator --()
{
    check_object(__LINE__);
    if (index >= 0)
        --index;

    return *this;
}

// логические операции
template<typename Type>
bool ConstIterator<Type>::operator <=(const ConstIterator<Type>& iterator) const
{
    check_object(__LINE__);

    return weakPtr <= iterator.weakPtr;
}

template<typename Type>
bool ConstIterator<Type>::operator <(const ConstIterator<Type>& iterator) const
{
    check_object(__LINE__);

    return weakPtr < iterator.weakPtr;
}

template<class Type>
bool ConstIterator<Type>::operator >=(const ConstIterator<Type>& iterator) const
{
    check_object(__LINE__);

    return weakPtr >= iterator.weakPtr;
}

template<typename Type>
bool ConstIterator<Type>::operator >(const ConstIterator<Type>& iterator) const
{
    check_object(__LINE__);

    return weakPtr > iterator.weakPtr;
}

template<typename Type>
bool ConstIterator<Type>::operator ==(const ConstIterator<Type>& iterator) const
{
    check_object(__LINE__);

    return weakPtr == iterator.weakPtr;
}

template<typename Type>
bool ConstIterator<Type>::operator !=(const ConstIterator<Type>& iterator) const
{
    check_object(__LINE__);

    return weakPtr != iterator.weakPtr;
}

template<typename Type>
ConstIterator<Type>::operator bool() const
{
    check_object(__LINE__);
    bool res = true;
    if (index >= size || index < 0 || size == 0)
        res = false;

    return res;
}

// проверки работы с объектом и итератором
template<typename Type>
void ConstIterator<Type>::check_object(int line) const
{
    if (weakPtr.expired())
    {
        time_t t_time = time(NULL);
        throw DeletedObject(__FILE__, typeid(*this).name(), line, ctime(&t_time));
    }
}

template<typename Type>
void ConstIterator<Type>::check_validity(int line) const {
    if (this->index >= this->size)
    {
        time_t currentTime = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), line, ctime(&currentTime));
    }
}

// достать текущий указатель на объект
template<typename Type>
Type* ConstIterator<Type>::get_cur_ptr() const
{
    std::shared_ptr<Type> copy_ptr = weakPtr.lock();
    return copy_ptr.get() + index;
}


#endif // CONST_ITERATOR_HPP
