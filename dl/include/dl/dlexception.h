#ifndef  __DLException_H_inventory_dl
#define  __DLException_H_inventory_dl 1
#include<iostream>
using namespace std;
namespace inventory_dl
{
class DLException:public exception
{
private:
string message;
public:
DLException();
DLException(string message);
DLException(const DLException &other);
DLException & operator=(const DLException &other);
virtual const char * what() const throw();
void setMessage(string message);
string getMessage();
virtual ~DLException() throw();
};
}
#endif