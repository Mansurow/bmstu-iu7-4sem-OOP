template <typename Type>
ConstMatrixIterator<Type>::ConstMatrixIterator()
        : matrix(std::weak_ptr<typename Matrix<Type>::MatrixRow[]>()),
          rows(0), cols(0), index(0)
{
}
template <typename Type>
ConstMatrixIterator<Type>::ConstMatrixIterator(const shared_ptr<typename Matrix<Type>::MatrixRow[]>& matrix_ptr, size_t rows, size_t cols, size_t ind)

        : matrix(matrix_ptr), rows(rows), cols(cols), index(ind)
{
}

template <typename Type>
void ConstMatrixIterator<Type>::check_index() const
{
    if (index < rows * cols)
        return;
    throw Index_Out_Of_Range_Exception( __FILE__, __LINE__, __TIME__, "index out of range");
}

template <typename Type>
void ConstMatrixIterator<Type>::check_nullptr() const
{
    if (matrix.expired())
    {
        throw Access_Non_Existing_Exception(__FILE__, __LINE__, __TIME__, "object doesn't exist");
    }
}

template <typename Type>
const Type& ConstMatrixIterator<Type>::operator*() const
{
    check_nullptr();
    check_index();
    shared_ptr<typename Matrix<Type>::MatrixRow[]> matr(matrix);
    return matr[index / cols][index % cols];
}

template <typename Type>
const Type* ConstMatrixIterator<Type>::operator->() const
{
    check_nullptr();
    check_index();
    shared_ptr<Type> matr(matrix);
    return matr[index / cols][index % cols];
}
template <typename Type>
ConstMatrixIterator<Type>& ConstMatrixIterator<Type>::operator =(const ConstMatrixIterator<Type> &other)
{
    matrix = other.matrix;
    rows = other.rows;
    cols = other.cols;
    index = other.index;
    return *this;
}
template <typename Type>
ConstMatrixIterator<Type>& ConstMatrixIterator<Type>::operator +=(size_t ind)
{
    index += ind;
    return *this;
}
template <typename Type>
ConstMatrixIterator<Type>& ConstMatrixIterator<Type>::operator -=(size_t ind)
{
    index -= ind;
    return *this;
}


template <typename Type>
ConstMatrixIterator<Type>& ConstMatrixIterator<Type>::operator++()
{
    if (index < rows * cols)
        index++;
    return *this;
}

template <typename Type>
ConstMatrixIterator<Type> ConstMatrixIterator<Type>::operator++(int)
{
    ConstMatrixIterator<Type> it(*this);
    ++(*this);
    return it;
}
template <typename Type>
ConstMatrixIterator<Type> ConstMatrixIterator<Type>::operator+(size_t ind)
{
    ConstMatrixIterator<Type> it = *this;
    it += ind;
    return it;
}

template <typename Type>
ConstMatrixIterator<Type>& ConstMatrixIterator<Type>::operator--()
{
    if (index < rows * cols)
        index--;
    return *this;
}

template <typename Type>
ConstMatrixIterator<Type> ConstMatrixIterator<Type>::operator--(int)
{
    ConstMatrixIterator<Type> it(*this);
    --(*this);
    return it;
}
template <typename Type>
ConstMatrixIterator<Type> ConstMatrixIterator<Type>::operator-(size_t ind)
{
    ConstMatrixIterator<Type> it = *this;
    it -= ind;
    return it;
}

template <typename T>
ConstMatrixIterator<T>::operator bool() const {
    return matrix.expired();
}

template <typename Type>
bool ConstMatrixIterator<Type>::operator==(ConstMatrixIterator const& other) const
{
    return index == other.index;
}

template <typename Type>
bool ConstMatrixIterator<Type>::operator!=(ConstMatrixIterator const& other) const
{
    return index != other.index;
}
template <typename Type>
bool ConstMatrixIterator<Type>::operator<(ConstMatrixIterator const& other) const
{
    return index < other.index;
}
template <typename Type>
bool ConstMatrixIterator<Type>::operator>(ConstMatrixIterator const& other) const
{
    return index > other.index;
}
template <typename Type>
bool ConstMatrixIterator<Type>::operator<=(ConstMatrixIterator const& other) const
{
    return index <= other.index;
}
template <typename Type>
bool ConstMatrixIterator<Type>::operator>=(ConstMatrixIterator const& other) const
{
    return index >= other.index;
}
