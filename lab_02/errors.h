#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <string>

class BaseError: public std::exception
{
public:
    BaseError(std::string filename,
              std::string classname,
              int line,
              const char *time,
              std::string info = "Error!")
    {
        error_info = "\nFile name: " + filename +
                     "\nClass: " + classname +
                     "\nLine: " + std::to_string(line) +
                     "\nTime: " + time +
                     "Info: " + info;
    }

    virtual const char* what() const noexcept override
    {
        return error_info.c_str();
    }

    virtual ~BaseError() {};

protected:
    std::string error_info;
};

class MemoryError: public BaseError
{
public:
    MemoryError(std::string filename,
                std::string classname,
                int line,
                const char *time,
                std::string info = "Memory allocation error!\n"):
        BaseError(filename, classname, line, time, info) {};
};

class DeletedObject: public BaseError
{
public:
    DeletedObject(std::string filename,
                std::string classname,
                int line,
                const char *time,
                std::string info = "Attempt to work with a remote object!\n"):
        BaseError(filename, classname, line, time, info) {};
};

class InvalidIterator : public BaseError
{
public:
    InvalidIterator(
        std::string filename,
        std::string classname,
        int line,
        const char *time,
        std::string info = "Attempt to use an invalid iterator!\n") :
    BaseError(filename, classname, line, time, info) {};
};

class EmptyVectorError : public BaseError
{
public:
    EmptyVectorError(std::string filename,
                     std::string classname,
                     int line, const char *time,
                     std::string info = "The size of the vector must be greater than 0!\n") :
    BaseError(filename, classname, line, time, info) {};
};

class IndexVectorError : public BaseError
{
public:
    IndexVectorError(std::string filename,
               std::string classname,
               int line, const char *time,
               std::string info = "Going beyond the vector limit!\n") :
    BaseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return error_info.c_str();
    }
};

class ZeroDivError : public BaseError
{
public:
    ZeroDivError(std::string filename,
                 std::string classname,
                 int line,
                 const char *time,
                 std::string info = "Division by zero is not allowed!\n") :
    BaseError(filename, classname, line, time, info) {};
};

class InvalidCopyArrayPointer : public BaseError
{
public:
    InvalidCopyArrayPointer(std::string filename,
                 std::string classname,
                 int line,
                 const char *time,
                 std::string info = "The original array does not exist!\n") :
    BaseError(filename, classname, line, time, info) {};
};

#endif // ERRORS_H
