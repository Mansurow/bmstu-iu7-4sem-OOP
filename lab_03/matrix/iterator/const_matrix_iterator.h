

#include <iostream>
# include <memory>

# include "../errors/errors.hpp"
using namespace std;

template <typename Type>
class Matrix;

template <typename Type>
class ConstMatrixIterator
{
public:
    //constructors
    ConstMatrixIterator();
    ConstMatrixIterator(const shared_ptr<typename Matrix<Type>::MatrixRow[]>& matrix_ptr, size_t rows, size_t cols, size_t ind = 0);
    ConstMatrixIterator(const ConstMatrixIterator &it) = default;

    // getting access

    const Type& operator*() const;
    const Type* operator->() const;
    
    // equals
    ConstMatrixIterator<Type>& operator =(const ConstMatrixIterator<Type> &other);
    ConstMatrixIterator<Type>& operator +=(size_t ind);
    ConstMatrixIterator<Type>& operator -=(size_t ind);

    // math
    ConstMatrixIterator<Type>& operator ++();
    ConstMatrixIterator<Type> operator ++(int);
    ConstMatrixIterator<Type> operator +(size_t ind);

    ConstMatrixIterator<Type>& operator --();
    ConstMatrixIterator<Type> operator --(int);
    ConstMatrixIterator<Type> operator -(size_t ind);

    // comparisons
    explicit operator bool() const;
    bool operator!=(ConstMatrixIterator const& other) const;
    bool operator==(ConstMatrixIterator const& other) const;
    bool operator<(ConstMatrixIterator const& other) const;
    bool operator>(ConstMatrixIterator const& other) const;
    bool operator<=(ConstMatrixIterator const& other) const;
    bool operator>=(ConstMatrixIterator const& other) const;
    
private:
    void check_index() const;
    void check_nullptr() const;
    weak_ptr <typename Matrix<Type>::MatrixRow[]> matrix;
    size_t cols;
    size_t rows;
    size_t index;
};

#include "const_matrix_iterator.hpp"