#ifndef __Item_Name_Comparator_cpp
#define  __Item_Name_Comparator_cpp 1
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<bl\ItemNameComparator.h>
#include<iostream>
#include<Utility.h>
using namespace tools;
using namespace std;
using namespace inventory_bl;
bool ItemNameComparator::operator()(I_Item *left,I_Item *right)
{
if(Utility::iCompareStrings(left->getName().c_str(),right->getName().c_str()) < 0) return true;
return false;
}
#endif