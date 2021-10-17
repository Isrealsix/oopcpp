#include "ArrayException.h"

ArrayException::ArrayException(int code) : std::exception()
{
    this->code = code;
}

const char* ArrayException::what() const throw()
{
    if (code == Error::MAX_SIZE_LESS_0) return "Exception Error: Maximum array size is lesser then zero(0)";
    if (code == Error::MAX_SIZE_ERROR) return "Exception Error: Incorrect maximum array size";
    if (code == Error::INDEX_ERROR) return "Exception Error: Incorrect Index";
    if (code == Error::INDEX_LESS_0) return "Exception Error: Index is less then zero(0)";
    if (code == Error::INDEX_BIGGER_MAX_SIZE) return "Exception Error: Index is greater then maximum array size";
    return "Unknown Exception Error has occured";
}
