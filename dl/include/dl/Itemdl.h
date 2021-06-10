#ifndef  __ItemDL_h_inventory_dl
#define  __ItemDL_h_inventory_dl 1
#include<dl\I_Item.h>
#include<dl\Item.h>
#include<iostream>
#include<forward_list>
#include <dl\I_ItemDL.h>
#include<string.h>
using namespace std;
namespace inventory_dl
{
class ItemDL:public I_ItemDL
{
static string DATA_FILE;
public:
void add(I_Item *item);
void update(I_Item *item);
void remove(int code);
I_Item * getByCode(int code);
I_Item *  getByName(string name);
forward_list<I_Item *> * getAll();
int getCount();
void removeAll();
};
}
#endif