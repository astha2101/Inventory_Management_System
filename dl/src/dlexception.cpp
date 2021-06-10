#ifndef  __DLException_cpp_inventory_dl
#define  __DLException_cpp_inventory_dl 1
#include<dl\DLException.h>
#include<iostream>
using namespace inventory_dl;
using namespace std;
DLException::DLException()
{
this->message=" ";
}
DLException::DLException(string message)
{
this->message=message;
}
DLException::DLException(const DLException &other)
{
this->message=other.message;
}
DLException & DLException::operator=(const DLException &other)
{
this->message=other.message;
return *this;
}
const char * DLException::what() const throw()
{
return this->message.c_str();
}
void DLException::setMessage(string message)
{
this->message=message;
}
string DLException::getMessage()
{
return this->message;
}
DLException::~DLException() throw()
{

}
#endif