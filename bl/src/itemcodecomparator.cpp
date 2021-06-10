#ifndef __Item_Code_Comparator_cpp
#define  __Item_Code_Comparator_cpp 1
#include<bl\I_Item.h>
#include<bl\ItemCodeComparator.h>
using namespace inventory_bl;
bool ItemCodeComparator::operator()(I_Item *left,I_Item *right)
{
if(left->getCode() < right->getCode()) return true;
return false;
}
#endif