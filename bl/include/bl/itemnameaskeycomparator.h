#ifndef __Item_Name_As_Key_Comparator_h_inventory_bl
#define  __Item_Name_As_Key_Comparator_h_inventory_bl 1
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<iostream>
using namespace std;
namespace inventory_bl
{
class ItemNameAsKeyComparator
{
public:
bool operator()(const char *left,const char  *right);
};
}
#endif