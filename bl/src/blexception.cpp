#ifndef  __BLException_cpp
#define  __BLException_cpp 1
#include<bl\BLException.h>
#include<iostream>
using namespace inventory_bl;
using namespace std;
BLException::BLException()
{
// do nothing
}
BLException::BLException(const BLException &other)
{
this->exceptions=other.exceptions;
}
BLException & BLException::operator=(const BLException &other)
{
this->exceptions=other.exceptions;
return *this;
}
const char * BLException::what() const throw()
{
//
return NULL;
}
void BLException::setGenericException(string message)
{
this->addException(GENERIC_EXCEPTION,message);
}
string BLException::getGenericException()
{
return this->getException(GENERIC_EXCEPTION);
}
void BLException::addException(__$$__BL_ENUMERATION property,string exception)
{
this->exceptions.insert(pair<__$$__BL_ENUMERATION,string>(property,exception));
}
bool BLException::hasExceptions()
{
if(this->exceptions.size() > 0) return true;
return false;
}
bool BLException::hasException(__$$__BL_ENUMERATION property)
{
map<__$$__BL_ENUMERATION,string>::iterator iter;
iter=this->exceptions.find(property);
if(iter!=this->exceptions.end()) return true;
return false;
}
map<__$$__BL_ENUMERATION,string> BLException::getExceptions()
{
return this->exceptions;
}
string BLException::getException(__$$__BL_ENUMERATION property)
{
map<__$$__BL_ENUMERATION,string>::iterator iter;
iter=this->exceptions.find(property);
if(iter!=this->exceptions.end()) return (*iter).second;
else return string(" ");
}
int BLException::size()
{
return this->exceptions.size();
}
BLException::~BLException() throw()
{
// do nothing
}
#endif