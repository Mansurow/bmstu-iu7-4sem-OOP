#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "matrix.h"

template <typename Type>
std::shared_ptr<typename Matrix<Type>::MatrixRow[]>
Matrix<Type>::alloc_matrix(size_t rows, size_t cols)
{
    std::shared_ptr<MatrixRow[]> matr_ptr(new MatrixRow[rows]);
    try
    {
        for (size_t i = 0; i < rows; i++)
            matr_ptr[i].reset(new Type[cols], cols);
    }
    catch (std::bad_alloc &err)
    {
        throw Memory_Allocation_Exception(__FILE__, __LINE__, __TIME__, "memory allocation error");
    }
    return matr_ptr;
}
template <typename Type>
Matrix<Type>::Matrix(size_t rows, size_t columns)
{
    this->rows = rows;
    this->cols = columns;
    this->matrix_ptr = alloc_matrix(rows, columns);
}
template <typename Type>
Matrix<Type>::Matrix(Type **c_matrix, size_t rows, size_t cols)
{
    this->rows = rows;
    this->cols = cols;
    this->matrix = alloc_matrix(rows, cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            matrix_ptr[i][j] = c_matrix[i][j];
}
template <typename Type>
Matrix<Type>::Matrix(size_t rows, size_t columns, const Type &filler)
{
    this->rows = rows;
    this->cols = columns;
    this->matrix = alloc_matrix(rows, columns);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < columns; ++j)
            matrix_ptr[i][j] = filler;
}
template <typename Type>
Matrix<Type>::Matrix(std::initializer_list<std::initializer_list<Type> > init_list)
{
    size_t rows = init_list.size();
    auto it = init_list.begin();
    size_t cols = it->size();

    for (const auto &row_list: init_list)
        if (row_list.size() != cols)
        {
            throw Wrong_Init_List_Exception(__FILE__, __LINE__, __TIME__, "wrong size of initializer row (must be equal)");
        }

    this->rows = rows;
    this->cols = cols;
    this->matrix_ptr = alloc_matrix(rows, cols);
    size_t i = 0;
    for (const auto &ilist: init_list)
        for (const auto &elem: ilist)
        {
            matrix_ptr[i / cols][i % cols] = elem;
            i++;
        }
}
template <typename Type>
Matrix<Type>::Matrix(const Matrix &matrix) : MatrixBase(matrix.rows, matrix.cols)
{
    this->matrix_ptr = alloc_matrix(matrix.rows, matrix.cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            matrix_ptr[i][j] = matrix[i][j];
}
template <typename Type>
Matrix<Type>::Matrix(Matrix &&matrix) noexcept
{
    this->rows = matrix.rows;
    this->cols = matrix.cols;
    this->matrix_ptr = matrix.matrix_ptr;
}
//equals
template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(const Matrix &matrix)
{
    this->rows = matrix.rows;
    this->cols = matrix.cols;
    this->matrix_ptr = alloc_matrix(matrix.rows, matrix.cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            matrix_ptr[i][j] = matrix[i][j];
    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(Matrix<Type> &&matrix) noexcept
{
    this->rows = matrix.rows;
    this->cols = matrix.cols;
    this->matrix_ptr = matrix.matrix_ptr;
    return *this;
}
template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(std::initializer_list<std::initializer_list<Type> > init_list)
{
    Matrix<Type>tmp = Matrix(init_list);
    *this = tmp;
    return *this;
}
// iterators
template <typename Type>
MatrixIterator<Type> Matrix<Type>::begin()
{
    MatrixIterator<Type> iter(matrix_ptr, rows, cols, 0);
    return iter;
}
template <typename Type>
MatrixIterator<Type> Matrix<Type>::end()
{
    MatrixIterator<Type> iter(matrix_ptr, rows, cols, cols * rows);
    return iter;
}
template <typename Type>
ConstMatrixIterator<Type> Matrix<Type>::begin() const
{
    ConstMatrixIterator<Type> iter(matrix_ptr, rows, cols, 0);
    return iter;
}
template <typename Type>
ConstMatrixIterator<Type> Matrix<Type>::end() const
{
    ConstMatrixIterator<Type> iter(matrix_ptr, rows, cols, cols * rows);
    return iter;
}
template <typename Type>
ConstMatrixIterator<Type> Matrix<Type>::cbegin() const
{
    ConstMatrixIterator<Type> iter(matrix_ptr, rows, cols, 0);
    return iter;
}
template <typename Type>
ConstMatrixIterator<Type> Matrix<Type>::cend() const
{
    ConstMatrixIterator<Type> iter(matrix_ptr, rows, cols, cols * rows);
    return iter;
}
template <typename Type>
bool Matrix<Type>::operator==(const Matrix& matrix) const
{
    ConstMatrixIterator<Type> lhs_iter = begin();
    ConstMatrixIterator<Type> rhs_iter = matrix.begin();

    for (; lhs_iter != this->end(); lhs_iter++, rhs_iter++)
    {
        if (*lhs_iter != *rhs_iter)
            return false;
    }
    if (rhs_iter != matrix.end())
        return false;
    return true;
}
template <typename Type>
bool Matrix<Type>::operator!=(const Matrix& matrix) const
{
    return !((*this) == matrix);
}
template <typename Type>
typename Matrix<Type>::MatrixRow & Matrix<Type>::operator[](size_t row)
{
    return matrix_ptr[row];
}
template <typename Type>
const typename Matrix<Type>::MatrixRow & Matrix<Type>::operator[](size_t row) const
{
    return matrix_ptr[row];
}
template <typename Type>
Matrix<Type> Matrix<Type>::operator+(const Matrix<Type> &matrix) const
{
    if (matrix.rows != rows || matrix.cols != cols)
    {
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__,
                                     "impossible to make operation: sizes of matrix are incorrect");
    }
    Matrix<Type> result(rows, cols);
    for (size_t i = 0; i < matrix.rows; i++)
        for (size_t j = 0; j < matrix.cols; j++)
            result[i][j] = matrix[i][j] + matrix_ptr[i][j];
    return result;
}
template <typename Type>
Matrix<Type> &Matrix<Type>::operator+=(const Matrix &matrix)
{
    if (matrix.rows != rows || matrix.cols != cols)
    {
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__,
                                     "impossible to make operation: sizes of matrix are incorrect");
    }
    for (size_t i = 0; i < matrix.rows; i++)
        for (size_t j = 0; j < matrix.cols; j++)
            matrix_ptr[i][j] += matrix[i][j];
    return *this;
}
template <typename Type>
Matrix<Type> Matrix<Type>::operator-(const Matrix<Type> &matrix) const
{
    if (matrix.rows != rows || matrix.cols != cols)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of matrix are incorrect");
    Matrix<Type> result(rows, cols);
    for (size_t i = 0; i < matrix.rows; i++)
        for (size_t j = 0; j < matrix.cols; j++)
            result[i][j] = matrix_ptr[i][j] - matrix[i][j];
    return result;
}
template <typename Type>
Matrix<Type> &Matrix<Type>::operator-=(const Matrix &matrix)
{
    if (matrix.rows != rows || matrix.cols != cols)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of matrix are incorrect");
    for (size_t i = 0; i < matrix.rows; i++)
        for (size_t j = 0; j < matrix.cols; j++)
            matrix_ptr[i][j] -= matrix[i][j];
    return *this;
}
template <typename Type>
Matrix<Type> Matrix<Type>::operator*(const Matrix<Type> &matrix) const
{
    if (cols != matrix.rows)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of matrix are incorrect");
    Matrix<Type> result(rows, matrix.cols);
    for (size_t i = 0; i < rows; i++)
        for (size_t k = 0; k < matrix.cols; k++)
        {
            result[i][k] = 0;
            for (size_t j = 0; j < cols; j++)
                result[i][k] += matrix_ptr[i][j] * matrix[j][k];
        }
    return result;
}
template <typename Type>
Matrix<Type> Matrix<Type>::operator*(const Type &elem) const noexcept
{
    Matrix<Type>res(*this);
    for (auto &el : res)
        el *= elem;
    return res;
}
template <typename Type>
Matrix<Type> &Matrix<Type>::operator*=(const Matrix &matrix)
{
    if (cols != matrix.rows)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of matrix are incorrect");
    Matrix<Type> result(rows, matrix.cols);
    for (size_t i = 0; i < rows; i++)
        for (size_t k = 0; k < matrix.cols; k++)
        {
            result[i][k] = 0;
            for (size_t j = 0; j < cols; j++)
                result[i][k] += matrix_ptr[i][j] * matrix[j][k];
        }
    *this = result;
    return *this;
}
template <typename Type>
Matrix<Type> &Matrix<Type>::operator*=(const Type &elem) noexcept
{
    for (auto &el : *this)
        el *= elem;
    return (*this);
}
template <typename Type>
Matrix<Type> Matrix<Type>::sum(const Matrix<Type> &matrix) const
{
    if (matrix.rows != rows || matrix.cols != cols)
    {
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__,
                                     "impossible to make operation: sizes of matrix are incorrect");
    }
    Matrix<Type> result(rows, cols);
    for (size_t i = 0; i < matrix.rows; i++)
        for (size_t j = 0; j < matrix.cols; j++)
            result[i][j] = matrix[i][j] + matrix_ptr[i][j];
    return result;
}
template <typename Type>
Matrix<Type> &Matrix<Type>::sum_eq(const Matrix &matrix)
{
    if (matrix.rows != rows || matrix.cols != cols)
    {
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__,
                                     "impossible to make operation: sizes of matrix are incorrect");
    }
    for (size_t i = 0; i < matrix.rows; i++)
        for (size_t j = 0; j < matrix.cols; j++)
            matrix_ptr[i][j] += matrix[i][j];
    return *this;
}
template <typename Type>
Matrix<Type> Matrix<Type>::sub(const Matrix<Type> &matrix) const
{
    if (matrix.rows != rows || matrix.cols != cols)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of matrix are incorrect");
    Matrix<Type> result(rows, cols);
    for (size_t i = 0; i < matrix.rows; i++)
        for (size_t j = 0; j < matrix.cols; j++)
            result[i][j] = matrix_ptr[i][j] - matrix[i][j];
    return result;
}
template <typename Type>
Matrix<Type> &Matrix<Type>::sub_eq(const Matrix &matrix)
{
    if (matrix.rows != rows || matrix.cols != cols)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of matrix are incorrect");
    for (size_t i = 0; i < matrix.rows; i++)
        for (size_t j = 0; j < matrix.cols; j++)
            matrix_ptr[i][j] -= matrix[i][j];
    return *this;
}
template <typename Type>
Matrix<Type> Matrix<Type>::mul_matrix(const Matrix<Type> &matrix) const
{
    if (cols != matrix.rows)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of matrix are incorrect");
    Matrix<Type> result(rows, matrix.cols);
    for (size_t i = 0; i < rows; i++)
        for (size_t k = 0; k < matrix.cols; k++)
        {
            result[i][k] = 0;
            for (size_t j = 0; j < cols; j++)
                result[i][k] += matrix_ptr[i][j] * matrix[j][k];
        }
    return result;
}
template <typename Type>
Matrix<Type> Matrix<Type>::mul_elem(const Type &elem) const noexcept
{
    Matrix<Type>res(*this);
    for (auto &el : res)
        el *= elem;
    return res;
}
template <typename Type>
Matrix<Type> &Matrix<Type>::mul_eq_matrix(const Matrix &matrix)
{
    if (cols != matrix.rows)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of matrix are incorrect");
    Matrix<Type> result(rows, matrix.cols);
    for (size_t i = 0; i < rows; i++)
        for (size_t k = 0; k < matrix.cols; k++)
        {
            result[i][k] = 0;
            for (size_t j = 0; j < cols; j++)
                result[i][k] += matrix_ptr[i][j] * matrix[j][k];
        }
    *this = result;
    return *this;
}
template <typename Type>
Matrix<Type> &Matrix<Type>::mul_eq_elem(const Type &elem) noexcept
{
    for (auto &el : *this)
        el *= elem;
    return (*this);
}
template <typename Type>
Matrix<Type> Matrix<Type>::make_minor(const Matrix<Type> &matr, size_t crossed_row, size_t crossed_col) const
{
    Matrix<Type>res(matr.rows - 1, matr.rows - 1);
    for (size_t i = 0, p = 0; i < matr.rows; ++i, ++p)
    {
        if (i == crossed_row) {
            --p;
            continue;
        }
        for (size_t j = 0, k = 0; j < matr.rows; ++j, ++k) {
            if (j == crossed_col) {
                --k;
                continue;
            }
            res[p][k] = matr[i][j];
        }
    }
    return res;
}
template <typename Type>
Type Matrix<Type>::_determinant(const Matrix<Type> &matr) const
{
    if (matr.rows == 1)
        return matr[0][0];
    if (matr.rows == 2)
        return (matr[1][1] * matr[0][0]) - (matr[0][1] * matr[1][0]);
    int sig = 1;
    Type ans = 0;
    for (size_t i = 0; i < matr.rows; ++i)
    {
        Matrix<Type> minor = make_minor(matr, 0, i);
        ans += sig * matr[0][i] * _determinant(minor);
        sig *= -1;
    }
    return ans;
}
template <typename Type>
Type Matrix<Type>::determinant() const
{
    if (cols != rows)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of matrix must be equal");
    Type ans = _determinant(*this);
    return ans;
}
template <typename Type>
void Matrix<Type>::transpose()
{
    Matrix<Type> tmp(cols, rows);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
            tmp[j][i] = matrix_ptr[i][j];
    }
    matrix_ptr = tmp.matrix_ptr;
    size_t tmp_st = rows;
    rows = cols;
    cols = tmp_st;
}
template <typename Type>
Matrix<Type> Matrix<Type>::transpose_matrix()
{
    Matrix<Type> tmp(cols, rows);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
            tmp[j][i] = matrix_ptr[i][j];
    }
    return tmp;
}
template <typename Type>
void Matrix<Type>::adjoint()
{
    if (cols != rows)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of adjoint matrix must be equal");

    if (cols == 1)
    {
        matrix_ptr[0][0] = 1.0;
        return;
    }

    Matrix<Type> copy(*this);
    Type val;
    int sig;
    for (size_t i = 0; i < rows; i++)
    {
        if (i % 2 == 0)
            sig = 1;
        else
            sig = -1;
        for (size_t j = 0; j < cols; j++)
        {
            Matrix<Type> tmp = make_minor(copy, i, j);
            val = tmp.determinant();
            matrix_ptr[j][i] = val * sig;
            sig *= -1;
        }
    }
}
template <typename Type>
Matrix<Type> Matrix<Type>::adjoint_matrix()
{
    if (cols != rows)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of adjoint matrix must be equal");

    Matrix<Type> res(*this);

    if (cols == 1)
    {
        res[0][0] = 1.0;
        return res;
    }

    Matrix<Type> copy(*this);
    Type val;
    int sig;
    for (size_t i = 0; i < rows; i++)
    {
        if (i % 2 == 0)
            sig = 1;
        else
            sig = -1;
        for (size_t j = 0; j < cols; j++)
        {
            Matrix<Type> tmp = make_minor(copy, i, j);
            val = tmp.determinant();
            res[j][i] = val * sig;
            sig *= -1;
        }
    }
    return res;
}
template <typename Type>
void Matrix<Type>::inverse()
{
    if (cols != rows)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of inverse matrix must be equal");

    Type det = determinant();
    adjoint();
    (*this) /= det;
}
template <typename Type>
Matrix<Type> Matrix<Type>::inverse_matrix()
{
    if (cols != rows)
        throw Sizes_Differ_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: sizes of inverse matrix must be equal");

    Type det = determinant();
    Matrix<Type> res(*this);
    res.adjoint();
    res /= det;
    return res;
}
template <typename Type>
Matrix<Type> Matrix<Type>::operator/(const Matrix<Type> &matrix) const
{
    Matrix<Type>res(matrix);
    res.inverse();
    res = (*this) * res;
    return res;
}
template <typename Type>
Matrix<Type> Matrix<Type>::operator/(const Type &elem) const
{
    Matrix<Type>res(*this);
    for (auto &el : res)
        el /= elem;
    return res;
}
template <typename Type>
Matrix<Type> &Matrix<Type>::operator/=(const Matrix &matrix)
{
    Matrix<Type> tmp(matrix);
    tmp.inverse();
    (*this) *= tmp;
    return (*this);
}
template <typename Type>
Matrix<Type> &Matrix<Type>::operator/=(const Type &elem)
{
    for (auto &el : *this)
        el /= elem;
    return (*this);
}
template <typename Type>
Matrix<Type> Matrix<Type>::operator-()
{
    Matrix<Type>res(*this);
    for (auto &el : res)
        el = -el;
    return res;
}
template <typename Type>
Matrix<Type> Matrix<Type>::div_matrix(const Matrix<Type> &matrix) const
{
    Matrix<Type>res(matrix);
    res.inverse();
    res = (*this) * res;
    return res;
}
template <typename Type>
Matrix<Type> Matrix<Type>::div_elem(const Type &elem) const
{
    Matrix<Type>res(*this);
    for (auto &el : res)
        el /= elem;
    return res;
}
template <typename Type>
Matrix<Type> &Matrix<Type>::div_eq_matrix(const Matrix &matrix)
{
    Matrix<Type> tmp(matrix);
    tmp.inverse();
    (*this) *= tmp;
    return (*this);
}
template <typename Type>
Matrix<Type> &Matrix<Type>::div_eq_elem(const Type &elem)
{
    for (auto &el : *this)
        el /= elem;
    return (*this);
}
template <typename Type>
Matrix<Type> Matrix<Type>::neg() {
    Matrix<Type> res(*this);
    for (auto &el : res)
        el = -el;
    return res;
}
template <typename Type>
void Matrix<Type>::resize(size_t new_rows, size_t new_cols, const Type &filler)
{
    Matrix<Type> tmp(new_rows, new_cols);
    for (size_t i = 0; i < new_rows; i++)
        for (size_t j = 0; j < new_cols; j++)
        {
            if (i < rows && j < cols)
                tmp[i][j] = (*this)[i][j];
            else
                tmp[i][j] = filler;
        }
    (*this) = tmp;
}
template <typename Type>
void Matrix<Type>::insert_row(size_t pos, const Type &filler)
{
    if (pos > rows)
        throw Index_Out_Of_Range_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: position is out of range");
    Matrix<Type> tmp(rows + 1, cols);
    for (size_t i = 0; i < rows + 1; i++)
        for (size_t j = 0; j < cols; j++)
        {
            if (i < pos)
                tmp[i][j] = (*this)[i][j];
            if (i == pos)
                tmp[i][j] = filler;
            if (i > pos)
                tmp[i][j] = (*this)[i - 1][j];
        }
    (*this) = tmp;
}
template <typename Type>
void Matrix<Type>::insert_col(size_t pos, const Type &filler)
{
    if (pos > cols)
        throw Index_Out_Of_Range_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: position is out of range");

    Matrix<Type> tmp(rows, cols + 1);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols + 1; j++)
        {
            if (j < pos)
                tmp[i][j] = (*this)[i][j];
            if (j == pos)
                tmp[i][j] = filler;
            if (j > pos)
                tmp[i][j] = (*this)[i][j - 1];
        }
    (*this) = tmp;
}

template <typename Type>
void Matrix<Type>::delete_row(size_t pos)
{
    if (pos >= rows)
        throw Index_Out_Of_Range_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: position is out of range");

    Matrix<Type> tmp(rows - 1, cols);
    for (size_t i = 0; i < rows - 1; i++)
        for (size_t j = 0; j < cols; j++)
        {
            if (i < pos)
                tmp[i][j] = (*this)[i][j];
            if (i >= pos)
                tmp[i][j] = (*this)[i + 1][j];
        }
    (*this) = tmp;
}
template <typename Type>
void Matrix<Type>::delete_col(size_t pos)
{
    if (pos >= cols)
        throw Index_Out_Of_Range_Exception(__FILE__, __LINE__, __TIME__, "impossible to make operation: position is out of range");

    Matrix<Type> tmp(rows, cols - 1);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols - 1; j++)
        {
            if (j < pos)
                tmp[i][j] = (*this)[i][j];
            if (j >= pos)
                tmp[i][j] = (*this)[i][j + 1];
        }
    (*this) = tmp;
}
template <typename Type>
ostream& operator<<(ostream& os, const Matrix<Type>& matr)
{
    size_t i = 0;
    for (ConstMatrixIterator<Type> iter = matr.cbegin(); iter != matr.cend(); iter++, i++) {
        *iter = 0;
        if ((i + 1) % matr.get_cols() == 0)
            cout << endl;
    }
    return os;
}
template <typename Type>
ostream& operator<<(ostream& os, Matrix<Type>& matr)
{
    size_t i = 0;
    for (ConstMatrixIterator<Type> iter = matr.cbegin(); iter != matr.cend(); iter++, i++) {
        cout << *iter << " ";
        if ((i + 1) % matr.get_cols() == 0)
            cout << endl;
    }
    return os;
}
template <typename Type>
Type &Matrix<Type>::MatrixRow::operator[](size_t index)
{
    if (index >= size)
    {
        throw Index_Out_Of_Range_Exception(__FILE__, __LINE__, __TIME__, "column index out of range");
    }
    return row[index];
}

template <typename Type>
const Type &Matrix<Type>::MatrixRow::operator[](size_t index) const
{
    if (index >= size)
    {
        throw Index_Out_Of_Range_Exception(__FILE__, __LINE__, __TIME__, "column index out of range");
    }
    return row[index];
}
template <typename Type>
void Matrix<Type>::MatrixRow::reset(Type *row, const size_t size) {
    this->size = size;
    this->row.reset(row);
}

template <typename Type>
void Matrix<Type>::MatrixRow::reset() {
    size = 0;
    row.reset();
}

#endif
