#ifndef  __Item_h_inventory_bl
#define  __Item_h_inventory_bl 1
#include<iostream>
#include <bl\I_Item.h>
#include<bl\bl.h>
using namespace std;
namespace inventory_bl
{
class Item:public I_Item
{
private:
int code;
string name;
string category;
public:
const char * get_name();
Item();
Item(int code,string name,__$$__BL_ENUMERATION category);
Item(const Item &other);
Item & operator=(const Item &other);
void setCode(int code);
int getCode();
void setName(string name);
string getName();
void setCategory(__$$__BL_ENUMERATION category);
string getCategory();
virtual ~Item();
friend class ItemManager;
};
}
#endif