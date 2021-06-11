#ifndef __INDEX_OUT_OF_BOUNDS_EXCEPTION_CPP
#define __INDEX_OUT_OF_BOUNDS_EXCEPTION_CPP 1
#include<iostream>
#include<IndexOutOfBoundsException>
using namespace std;
using namespace exceptions;
IndexOutOfBoundsException::IndexOutOfBoundsException()
{
}
IndexOutOfBoundsException::IndexOutOfBoundsException(string message)
{
this->message=message;
}
IndexOutOfBoundsException::IndexOutOfBoundsException(const IndexOutOfBoundsException &other)
{
this->message=other.message;
}
IndexOutOfBoundsException & IndexOutOfBoundsException::operator=(const IndexOutOfBoundsException &other)
{
this->message=other.message;
return *this;
}
IndexOutOfBoundsException::~IndexOutOfBoundsException() throw()
{
}
const char * IndexOutOfBoundsException::what() const throw()
{
return this->message.c_str();
}
void IndexOutOfBoundsException::setMessage(string message)
{
this->message=message;
}
string IndexOutOfBoundsException::getMessage()
{
return this->message;
}
#endif