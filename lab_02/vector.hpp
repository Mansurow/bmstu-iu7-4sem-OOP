#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector.h>

// Конструктор инициализации.
template<typename Type>
Vector<Type>::Vector()
{
    size = 0;
    allocNewVectorMem(size);
}

// Конструктор вектора нужной длины
template<typename Type>
Vector<Type>::Vector(int len)
{
    time_t curTime = time(NULL);
    if (len < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    size = len;
    allocNewVectorMem(size);
    if (!values)
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iterator = 0;
}

// Конструктор на основе массива.
template<typename Type>
Vector<Type>::Vector(int len, Type* array)
{
    time_t curTime = time(NULL);
    if (len <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    if (!array)
        throw InvalidCopyArrayPointer(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    size = len;
    allocNewVectorMem(size);
    if(!values)
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    Iterator<Type> iterator(*this);
    for (int i = 0; iterator; i++, iterator++)
        *iterator = array[i];
}

// Конструктор на основе элементов.
template<typename Type>
Vector<Type>::Vector(int len, Type vector, ...) {
    time_t currentTime = time(NULL);
    if (len < 1)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    size = len;
    allocNewVectorMem(size);
    if (!values)
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    va_list var;
    va_start(var, vector);
    for (; iterator; iterator++)
    {
        *iterator = vector;
        vector = va_arg(var, Type);
    }
    va_end(var);
}

// Конструктор с инициализацией.
template<typename Type>
Vector<Type>::Vector(std::initializer_list<Type> args) {
    if (args.size() == 0)
    {
        Vector();
        return;
    }

    time_t currentTime = time(NULL);
    size = int(args.size());
    allocNewVectorMem(size);
    if (!values)
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (auto &currentItem : args)
    {
        *iterator = currentItem;
        iterator++;
    }
}

// Конструктор от вектора.
template<typename Type>
Vector<Type>:: Vector(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    size = vector.size;
    allocNewVectorMem(size);
    if (!values)
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Iterator<Type> iteratorTo(*this);
    Iterator<Type> iteratorFrom(vector);
    for (; iteratorTo; iteratorFrom++, iteratorTo++)
        *iteratorTo = *iteratorFrom;
}

// Конструктор переносом.
template<typename Type>
Vector<Type>:: Vector(Vector<Type> &&vector) {
    time_t currentTime = time(NULL);

    size = vector.size;
    allocNewVectorMem(size);
    if (!values)
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    values = vector.values;
    vector.values = nullptr;
}

// Деструктор.
template<typename Type>
Vector<Type>::~Vector() {
    if (values)
        values.reset();
}

// Операторы присваивания
template<typename Type>
Vector<Type> &Vector<Type>::operator =(const Vector<Type> &vector)
{
    time_t curTime = time(NULL);
    size = vector.size;
    allocNewVectorMem(size);
    if (!values)
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    Iterator<Type> iteratorTo(*this);
    Iterator<Type> iteratorFrom(vector);
    for (; iteratorTo; iteratorFrom++, iteratorTo++)
        *iteratorTo = *iteratorFrom;

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator =(initializer_list<Type> args)
{
    time_t currentTime = time(NULL);
    size = int(args.size());
    allocNewVectorMem(size);
    if (!values)
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (auto &currentItem : args)
    {
        *iterator = currentItem;
        iterator++;
    }

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator =(Vector<Type> &&vector)
{
    time_t curTime = time(NULL);
    size = vector.size;
    allocNewVectorMem(size);
    if (!values)
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    values = vector.values;
    vector.values = nullptr;

    return *this;
}

// Получение элемента по индексу.
template<typename Type>
Type &Vector<Type>::getItem(int index) {
    time_t currentTime = time(NULL);
    if (index < 0 || index >= size)
        throw IndexVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    Iterator<Type> iterator(*this);
    for (int i = 0; i < index; i++, iterator++) { }
    return *iterator;
}

// Получение элемента по индексу Const.
template<typename Type>
const Type &Vector<Type>::getItem(int index) const {
    time_t currentTime = time(NULL);
    if (index < 0 || index >= size)
        throw IndexVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (int i = 0; i < index; i++, iterator++) { }

    return *iterator;
}

template<typename Type>
int Vector<Type>::getSize() const noexcept
{
    return size;
}

template<typename Type>
bool Vector<Type>::isEmpty() const noexcept
{
    return bool(size);
}

// Установить значени по индексу
template<typename Type>
bool Vector<Type>::setItem (int index, const Type &item)
{
    bool res = true;
    if (index < 0 || index >= size)
            res = false;
    else
    {
        Iterator<Type> iterator(*this);
        for (int i = 0; i < index; i++, iterator++);
        (*iterator) = item;
    }
    return res;
}

// Оператор индексации.
template<typename Type>
Type &Vector<Type>::operator[] (int index) {
    return getItem(index);
}

// Оператор индексации Const.
template<typename Type>
const Type &Vector<Type>::operator [](int index) const {
    return getItem(index);
}

// Проверка на нулевой вектор - длина равная 0
template<typename Type>
bool Vector<Type>::isSingle() const
{
    if (fabs(getLength() - 1) < __DBL_EPSILON__)
        return true;
    return false;
}

// Проверка на единичный вектор - длина равная 1
template<typename Type>
bool Vector<Type>::isZero() const
{
    if (getLength() == 0)
        return true;
    return false;
}

// вычисление длины вектора
template<typename Type>
double Vector<Type>::getLength() const
{
    time_t curTime = time(NULL);
    if (size < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    Iterator<Type> iterator(*this);
    double sum = 0;
    for (; iterator; iterator++)
        sum += *iterator * *iterator;
    sum = sqrt(sum);
    return sum;
}

// получение единичного вектора
template<typename Type>
Vector<Type> Vector<Type>::getSingle() const
{
    time_t curTime = time(NULL);
    if (size <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    Vector<Type> singleVector(*this);

    Type len = getLength();
    Iterator<Type> iterator(singleVector);

    for (; iterator; iterator++)
        *iterator /= len;
    return singleVector;
}

// Опредление угла между векторами
template<typename Type>
double Vector<Type>::angleBetweenVectors(const Vector<Type> &vector) const
{
    time_t curTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    if (!this->getLength() || !vector.getLength())
        throw ZeroDivError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    double angle = (*this * vector) / (this->getLength() * vector.getLength());
    if (angle > 1) angle = 1.0;

    return acos(angle) * 180 / M_PI;
}

// Проверка на коллинерность вектора
template<typename Type>
bool Vector<Type>::isCollinear(const Vector<Type>& vector) const
{
    time_t curTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    if (angleBetweenVectors(vector) < 1e-05)
        return true;
    return false;
}

// Проверка на ортогональность вектора
template<typename Type>
bool Vector<Type>::isOrthgonal(const Vector<Type>& vector) const
{
    time_t curTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    if (fabs(angleBetweenVectors(vector) - 90) < __DBL_EPSILON__)
        return true;
    return false;
}


// Умножить на число
template<typename Type>
Vector<Type> Vector<Type>::operator *(const Type &num) const
{
    time_t curTime = time(NULL);
    if (size <= 0)
        EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    Vector<Type> new_vector(*this);
    Iterator<Type> iterator(new_vector);
    for (; iterator; iterator++)
        *iterator *= num;

    return new_vector;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator *=(const Type &num)
{
    time_t currentTime = time(NULL);
    if (size < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iterator *= num;
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::mul(const Type &num)
{
    time_t currentTime = time(NULL);
    if (size < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iterator *= num;
    return *this;
}

// Скалярное произведение
template<typename Type>
Type Vector<Type>::operator *(const Vector<Type> &vector) const
{
    time_t curTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    int maxLength = max(size, vector.size);
    Vector<Type> newVector(maxLength);
    vecMul(newVector, *this, vector);
    return newVector.sumValue();
}

template<typename Type>
Type Vector<Type>::operator *=(const Vector<Type> &vector)
{
    time_t curTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    vecMul(*this, *this, vector);
    return sumValue();
}

template<typename Type>
Type Vector<Type>::scalarMul(const Vector<Type> &vector) const
{
    time_t curTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    int maxLength = max(size, vector.size);
    Vector<Type> newVector(maxLength);
    vecMul(newVector, *this, vector);
    return newVector.sumValue();
}

// Векторное произведение
template<typename Type>
Vector<Type> Vector<Type>::operator &(const Vector<Type> &vector) const
{
    time_t curTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    if (size != 3)
        return Vector<Type>();

    Type x = values.get()[1] * vector.values.get()[2] - values.get()[2] * vector.values.get()[1];
    Type y = values.get()[2] * vector.values.get()[0] - values.get()[0] * vector.values.get()[2];
    Type z = values.get()[0] * vector.values.get()[1] - values.get()[1] * vector.values.get()[0];

    Vector<Type> new_vector(3, x, y, z);
    return new_vector;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator &=(const Vector<Type>& vector)
{
    time_t curTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    if (size != 3)
        return *(new Vector<Type>);

    Type x = values.get()[1] * vector.values.get()[2] - values.get()[2] * vector.values.get()[1];
    Type y = values.get()[2] * vector.values.get()[0] - values.get()[0] * vector.values.get()[2];
    Type z = values.get()[0] * vector.values.get()[1] - values.get()[1] * vector.values.get()[0];

    *this = Vector<Type>(3, x, y, z);
    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::vectorMul(const Vector<Type>& vector)
{
    time_t curTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    if (size != 3)
        return *(new Vector<Type>);

    Type x = values.get()[1] * vector.values.get()[2] - values.get()[2] * vector.values.get()[1];
    Type y = values.get()[2] * vector.values.get()[0] - values.get()[0] * vector.values.get()[2];
    Type z = values.get()[0] * vector.values.get()[1] - values.get()[1] * vector.values.get()[0];

    *this = Vector<Type>(3, x, y, z);
    return *this;
}

// Деление вектора на число
template<typename Type>
Vector<Type> &Vector<Type>::operator /=(const Type& number)
{
    time_t curTime = time(NULL);
    if (size <= 0)
       throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    if (number == 0)
        throw ZeroDivError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
       *iterator /= number;
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::div(const Type& number)
{
    time_t curTime = time(NULL);
    if (size <= 0)
       throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    if (number == 0)
        throw ZeroDivError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
       *iterator /= number;
    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator /(const Type& number) const
{
    time_t curTime = time(NULL);
    if (size <= 0)
       throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    if (number == 0)
        throw ZeroDivError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));

    Vector<Type> new_vector(*this);
    Iterator<Type> iterator(new_vector);
    for (; iterator; iterator++)
       *iterator /= number;
    return new_vector;
}

// Равны ли вектора.
template<typename Type>
bool Vector<Type>::operator ==(const Vector<Type> &vector) const {
    bool res = true;
    time_t currentTime = time(NULL);
    if (size < 0 || vector.vector_size < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    if (size != vector.size)
        res = true;
    else
    {
        Iterator<Type> fIter(*this);
        Iterator<Type> sIter(vector);
        for (; res && fIter; sIter++, fIter++)
            if (fabs(*fIter - *sIter) > __DBL_EPSILON__)
                res = false;
    }

    return res;
}

// Различны ли вектора.
template<typename Type>
bool Vector<Type>::operator !=(const Vector<Type> &vector) const {
    bool res = false;
    time_t currentTime = time(NULL);
    if (size < 0 || vector.vector_size < 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    if (size != vector.size)
        res = true;
    else
    {
        Iterator<Type> fIter(*this);
        Iterator<Type> sIter(vector);

        for (; !res && fIter; sIter++)
            if (*fIter != *sIter)
                res = true;
    }

    return res;
}

// Суммирование всех элементов.
template<typename Type>
Type Vector<Type>::sumValue()
{
    time_t currentTime = time(NULL);
    if (size <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    Type summary = 0;
    for (; iterator; iterator++)
        summary += *iterator;

    return summary;
}

// Сумма векторов
template<typename Type>
Vector<Type> Vector<Type>::operator +(const Vector<Type> &vector) const{
    time_t currentTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    size_t maxLength = max(size, vector.size);
    Vector<Type> newVector(maxLength);
    vecSum(newVector, *this, vector);
    return newVector;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator +=(const Vector<Type> &vector) {
    time_t currentTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    vecSum(*this, *this, vector);

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::sum(const Vector<Type> &vector)
{
    time_t t_time = time(NULL);
    if (size <= 0 || vector.size <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
     sum_vectors(*this, *this, vector);

     return *this;
}

// Разность векторов.
template<typename Type>
Vector<Type> Vector<Type>::operator -(const Vector<Type> &vector) const
{
    time_t currentTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    int maxLength = std::max(size, vector.size);
    Vector<Type> newVector(maxLength);
    vecSub(newVector, *this, vector);

    return newVector;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator -=(const Vector<Type> &vector)
{
    time_t currentTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    vecSub(*this, *this, vector);
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::sub(const Vector<Type> &vector)
{
    time_t currentTime = time(NULL);
    if (size <= 0 || vector.size <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    vecSub(*this, *this, vector);
    return *this;
}

// Оператор вычитания вектора из самого себя.
template<typename Type>
Vector<Type> Vector<Type>::operator -()
{
    time_t currentTime = time(NULL);
    if (size <= 0)
        throw EmptyVectorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Vector<Type> newVector(*this);
    Iterator<Type> iterator(newVector);
    for (; iterator; iterator++)
        *iterator = -*iterator;
    return newVector;
}

// Сумма двух векторов.
template <typename Type>
void Vector<Type>::vecSum(Vector<Type> &res, const Vector<Type> &fV, const Vector<Type> &sV) const
{
    Iterator<Type> resIter(res);
    Iterator<Type> fIter(fV);
    Iterator<Type> sIter(sV);
    for (int i = 0; resIter; i++, resIter++, fIter++, sIter++)
    {
        if (i < fV.size && i < sV.size)
            *resIter = *fIter + *sIter;
        else if (i >= fV.size)
            *resIter = *fIter;
        else
            *resIter = *sIter;
    }
}

// Разница двух векторов.
template<typename Type>
void Vector<Type>::vecSub(Vector<Type> &res, const Vector<Type> &fV, const Vector<Type> &sV) const {
    Iterator<Type> resIter(res);
    Iterator<Type> fIter(fV);
    Iterator<Type> sIter(sV);
    for (int i = 0; resIter; i++, resIter++, fIter++, sIter++)
    {
        if (i < fV.size && i < sV.size)
            *resIter = *fIter - *sIter;
        else if (i >= fV.size)
            *resIter = *fIter;
        else
            *resIter = -*sIter;
    }
}

// Произведение двух векторов.
template<typename Type>
void Vector<Type>::vecMul(Vector<Type> &res, const Vector<Type> &fV, const Vector<Type> &sV) const{
    Iterator<Type> resIter(res);
    Iterator<Type> fIter(fV);
    Iterator<Type> sIter(sV);
    for (int i = 0; resIter; i++, resIter++, fIter++, sIter++)
    {
        if (i < fV.size && i < sV.size)
            *resIter = *fIter * *sIter;
        else
            *resIter = 0;
    }
}

// Выделение памяти под новый вектор.
template<typename Type>
void Vector<Type>::allocNewVectorMem(int amount) {
    time_t currentTime = time(NULL);
    try
    {
        values.reset();
    }
    catch (std::bad_alloc &exception)
    {
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }
    std::shared_ptr<Type> temp(new Type[amount], std::default_delete<Type[]>());
    values = temp;
}


template<typename Type>
Iterator<Type> Vector<Type>::begin() noexcept {
    Iterator<Type> iterator(*this);
    return iterator;
}

template<typename Type>
Iterator<Type> Vector<Type>::end() noexcept{
    Iterator<Type> iterator(*this);
    return iterator + this->size;
}

#endif // VECTOR_HPP
