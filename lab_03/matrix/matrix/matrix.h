#ifndef MATRIX_H
#define MATRIX_H

#include <memory>

#include "const_matrix_iterator.h"
#include "matrix_base.hpp"
#include "matrix_iterator.h"


template <typename Type>
class Matrix final: public MatrixBase
{
public:
    class MatrixRow;
    
    explicit Matrix(size_t rows = 0, size_t columns = 0);
    Matrix(size_t rows, size_t columns, const Type &filler);
    Matrix(std::initializer_list<std::initializer_list<Type> > init_list);
    Matrix(Type **c_matrix, size_t rows, size_t cols); //

    explicit Matrix(const Matrix &matrix);
    Matrix(Matrix &&matrix) noexcept;

    Matrix<Type> &operator=(const Matrix &matrix);
    Matrix<Type> &operator=(Matrix &&matrix) noexcept;
    Matrix<Type> &operator=(std::initializer_list<std::initializer_list<Type> > init_list);

    virtual ~Matrix() = default;

    // iterators
    MatrixIterator<Type> begin();
    MatrixIterator<Type> end();
    ConstMatrixIterator<Type> begin() const;
    ConstMatrixIterator<Type> end() const;

    ConstMatrixIterator<Type> cbegin() const;
    ConstMatrixIterator<Type> cend() const;

    // comparisons
    bool operator==(const Matrix& matrix) const;
    bool operator!=(const Matrix& matrix) const;

    // math

    Matrix<Type> operator+(const Matrix &matrix) const;
    Matrix<Type> &operator+=(const Matrix &matrix);

    Matrix<Type> operator-(const Matrix &matrix) const;
    Matrix<Type> &operator-=(const Matrix &matrix);

    Matrix<Type> operator*(const Matrix &matrix) const;
    Matrix<Type> &operator*=(const Matrix &matrix);
    Matrix<Type> operator*(const Type &elem) const noexcept;
    Matrix<Type> &operator*=(const Type &elem) noexcept;

    Matrix<Type> operator/(const Matrix &matrix) const;
    Matrix<Type> &operator/=(const Matrix &matrix);
    Matrix<Type> operator/(const Type &elem) const;
    Matrix<Type> &operator/=(const Type &elem);

    Matrix<Type> operator-();

    Matrix<Type> sum(const Matrix &matrix) const;
    Matrix<Type> &sum_eq(const Matrix &matrix);

    Matrix<Type> sub(const Matrix &matrix) const;
    Matrix<Type> &sub_eq(const Matrix &matrix);

    Matrix<Type> mul_matrix(const Matrix &matrix) const;
    Matrix<Type> &mul_eq_matrix(const Matrix &matrix);
    Matrix<Type> mul_elem(const Type &elem) const noexcept;
    Matrix<Type> &mul_eq_elem(const Type &elem) noexcept;

    Matrix<Type> div_matrix(const Matrix &matrix) const;
    Matrix<Type> &div_eq_matrix(const Matrix &matrix);
    Matrix<Type> div_elem(const Type &elem) const;
    Matrix<Type> &div_eq_elem(const Type &elem);

    Matrix<Type> neg();

    Matrix<Type> transpose_matrix();
    Matrix<Type> adjoint_matrix();
    Matrix<Type> inverse_matrix();

    Type determinant() const;
    void transpose();
    void adjoint();
    void inverse();

    void resize(size_t new_rows, size_t new_cols, const Type &filler = { });

    void insert_row(size_t pos, const Type &filler);
    void insert_col(size_t pos, const Type &filler);

    void delete_row(size_t pos);
    void delete_col(size_t pos);

    MatrixRow &operator[](size_t row);
    const MatrixRow &operator[](size_t row) const;

private:
    std::shared_ptr<MatrixRow[]> matrix_ptr { nullptr };
    std::shared_ptr<MatrixRow[]> alloc_matrix(size_t rows, size_t cols);
    Type _determinant(const Matrix<Type> &matr) const;
    Matrix<Type> make_minor(const Matrix<Type> &matr, size_t crossed_row, size_t crossed_col) const;

public:
    class MatrixRow {
    private:
        std::shared_ptr<Type[]> row;
        size_t size;

    public:
        MatrixRow(Type *row, const size_t size): row(row), size(size) { }
        MatrixRow(): row(nullptr), size(0) { }

        Type &operator[](size_t index);
        const Type &operator[](size_t index) const;
        void reset();
        void reset(Type *row, size_t size);
    };
};

#include "matrix.hpp"

#endif
