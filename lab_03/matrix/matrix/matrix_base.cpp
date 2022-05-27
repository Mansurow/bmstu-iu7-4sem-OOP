#include "matrix_base.hpp"

MatrixBase::MatrixBase(size_t rows, size_t columns):
    rows(rows), cols(columns)
{
}
size_t MatrixBase::get_cols() const noexcept
{
    return cols;
}
size_t MatrixBase::get_rows() const noexcept
{
    return rows;
};
MatrixBase::operator bool() const noexcept
{
    return cols && rows;
}
MatrixBase::~MatrixBase() { }
