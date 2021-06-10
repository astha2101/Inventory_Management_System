#ifndef  __I_Item_h_inventory_bl
#define __I_Item_h_inventory_bl 1
#include<iostream>
#include<bl\bl.h>
#include<Serializable.h>
using namespace ObjectIO;
using namespace std;
namespace inventory_bl
{
class I_Item
{
public:
virtual const char * get_name()=0;
virtual void setCode(int code)=0;
virtual int getCode()=0;
virtual void setName(string name)=0;
virtual string getName()=0;
virtual void setCategory(__$$__BL_ENUMERATION category)=0;
virtual string getCategory()=0;
friend class ItemManager;
};
}
#endif