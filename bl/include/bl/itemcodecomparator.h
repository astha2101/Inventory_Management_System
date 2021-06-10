#ifndef __Item_Code_Comparator_h_inventory_bl
#define  __Item_Code_Comparator_h_inventory_bl 1
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<string.h>
#include<iostream>
using namespace std;
namespace inventory_bl
{
class ItemCodeComparator
{
public:
bool operator()(I_Item *left,I_Item *right);
};
}
#endif