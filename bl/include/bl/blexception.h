#ifndef  __BLException_H_inventory_bl
#define  __BLException_H_inventory_bl 1
#include<bl\I_Item.h>
#include<bl\bl.h>
#include<map>
#include<utility>
#include<iostream>
using namespace std;
namespace inventory_bl
{
class BLException:public exception
{
private:
map<__$$__BL_ENUMERATION,string> exceptions;
public:
BLException();
BLException(const BLException &other);
BLException & operator=(const BLException &other);
virtual const char * what() const throw();
void setGenericException(string message);
string getGenericException();
void addException(__$$__BL_ENUMERATION,string);
bool hasExceptions();
bool hasException(__$$__BL_ENUMERATION);
map<__$$__BL_ENUMERATION,string> getExceptions();
string getException(__$$__BL_ENUMERATION);
int size();
virtual ~BLException() throw();
};
}
#endif