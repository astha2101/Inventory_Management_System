#ifndef __Item_Name_Comparator_h_inventory_bl
#define  __Item_Name_Comparator_h_inventory_bl 1
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<iostream>
using namespace std;
namespace inventory_bl
{
class ItemNameComparator
{
public:
bool operator()(I_Item *left,I_Item *right);
};
}
#endif