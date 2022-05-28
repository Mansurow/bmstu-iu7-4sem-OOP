
#include "errors.hpp"

Matrix_Exception::Matrix_Exception(const char* file, int line, const char* time, const char* msg)
{
    this->err_str = (char *)malloc(strlen(file) + strlen(time) + strlen(msg) + 40);
    sprintf(this->err_str, "file: %s, line: %-3d, time: %s, error: %s", file, line, time, msg);
}
Matrix_Exception::~Matrix_Exception()
{
    delete[] err_str;
}
const char * Matrix_Exception::what() const noexcept
{
    return this->err_str;
}


Index_Out_Of_Range_Exception::Index_Out_Of_Range_Exception(const char* file, int line, const char* time, const char* msg) :
        Matrix_Exception(file, line, time, msg)
{
}
Index_Out_Of_Range_Exception::~Index_Out_Of_Range_Exception()
{
    delete[] err_str;
}
const char * Index_Out_Of_Range_Exception::what() const noexcept
{
    return this->err_str;
}


Access_Non_Existing_Exception::Access_Non_Existing_Exception(const char* file, int line, const char* time, const char* msg) :
        Matrix_Exception(file, line, time, msg)
{
}
Access_Non_Existing_Exception::~Access_Non_Existing_Exception()
{
    delete[] err_str;
}
const char * Access_Non_Existing_Exception::what() const noexcept
{
    return this->err_str;
}

Memory_Allocation_Exception::Memory_Allocation_Exception(const char* file, int line, const char* time, const char* msg) :
        Matrix_Exception(file, line, time, msg)
{
}
Memory_Allocation_Exception::~Memory_Allocation_Exception()
{
    delete[] err_str;
}
const char * Memory_Allocation_Exception::what() const noexcept
{
    return this->err_str;
}

Wrong_Init_List_Exception::Wrong_Init_List_Exception(const char* file, int line, const char* time, const char* msg) :
        Matrix_Exception(file, line, time, msg)
{
}
Wrong_Init_List_Exception::~Wrong_Init_List_Exception()
{
    delete[] err_str;
}
const char * Wrong_Init_List_Exception::what() const noexcept
{
    return this->err_str;
}

Sizes_Differ_Exception::Sizes_Differ_Exception(const char* file, int line, const char* time, const char* msg) :
        Matrix_Exception(file, line, time, msg)
{
}
Sizes_Differ_Exception::~Sizes_Differ_Exception()
{
    delete[] err_str;
}
const char * Sizes_Differ_Exception::what() const noexcept
{
    return this->err_str;
}