
#ifndef errors_hpp
#define errors_hpp

#include <exception>
#include <string>
#include <string.h>
class Matrix_Exception : public std::exception //base_matrix nam
{
public:
    Matrix_Exception(const char* file, int line, const char* time, const char* msg);
    
    virtual ~Matrix_Exception();
    
    virtual const char * what() const noexcept override;
    
protected:
    char * err_str;
};


class Index_Out_Of_Range_Exception : public Matrix_Exception
{
public:
    Index_Out_Of_Range_Exception(const char* file, int line, const char* time, const char* msg);
    
    virtual const char *what() const noexcept override;
    
    virtual ~Index_Out_Of_Range_Exception();
    
};

class Access_Non_Existing_Exception : public Matrix_Exception
{
public:
    Access_Non_Existing_Exception(const char* file, int line, const char* time, const char* msg);
    
    virtual const char *what() const noexcept override;
    
    virtual ~Access_Non_Existing_Exception();
    
};

class Memory_Allocation_Exception : public Matrix_Exception
{
public:
    Memory_Allocation_Exception(const char* file, int line, const char* time, const char* msg);
    
    virtual const char *what() const noexcept override;
    
    virtual ~Memory_Allocation_Exception();
    
};

class Wrong_Init_List_Exception : public Matrix_Exception
{
public:
    Wrong_Init_List_Exception(const char* file, int line, const char* time, const char* msg);
    
    virtual const char *what() const noexcept override;
    
    virtual ~Wrong_Init_List_Exception();
    
};

class Sizes_Differ_Exception : public Matrix_Exception
{
public:
    Sizes_Differ_Exception(const char* file, int line, const char* time, const char* msg);

    virtual const char *what() const noexcept override;

    virtual ~Sizes_Differ_Exception();

};
#endif /* errors_hpp */
