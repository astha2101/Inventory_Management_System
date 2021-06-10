#ifndef __Item_Category_Comparator_cpp
#define  __Item_Category_Comparator_cpp 1
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<bl\ItemCategoryComparator.h>
#include<iostream>
#include<Utility.h>
using namespace tools;
using namespace std;
using namespace inventory_bl;
bool ItemCategoryComparator::operator()(I_Item *left,I_Item *right)
{
if(Utility::iCompareStrings(left->getCategory().c_str(),right->getCategory().c_str()) < 0) return true;
return false;
}
#endif