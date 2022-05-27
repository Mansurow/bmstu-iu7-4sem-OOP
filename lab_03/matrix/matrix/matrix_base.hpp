#ifndef MATRIX_BASE_HPP
#define MATRIX_BASE_HPP

#include <stdio.h>


class MatrixBase {
public:
    MatrixBase(size_t rows = 0, size_t columns = 0);

    virtual size_t get_cols() const noexcept;
    
    virtual size_t get_rows() const noexcept;
    
    virtual operator bool() const noexcept;

    virtual ~MatrixBase() = 0;

protected:
    size_t rows, cols;
};

#endif /* MatrixBase_hpp */
