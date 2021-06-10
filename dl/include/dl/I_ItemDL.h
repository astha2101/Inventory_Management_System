#ifndef  __I_ItemDL_h_inventory_dl
#define  __I_ItemDL_h_inventory_dl 1
#include<dl\I_Item.h>
#include<dl\Item.h>
#include<iostream>
#include<forward_list>
using namespace std;
namespace inventory_dl
{
class I_ItemDL
{
public:
virtual void add(I_Item *item)=0;
virtual void update(I_Item *item)=0;
virtual void remove(int code)=0;
virtual  I_Item * getByCode(int code)=0;
virtual I_Item *  getByName(string name)=0;
virtual forward_list<I_Item *> * getAll()=0;
virtual int getCount()=0;
virtual void removeAll()=0;
};
}
#endif