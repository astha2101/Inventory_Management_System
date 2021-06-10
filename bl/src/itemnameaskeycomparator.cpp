#ifndef __Item_Name_As_Key_Comparator_cpp
#define  __Item_Name_As_Key_Comparator_cpp 1
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<bl\ItemNameAsKeyComparator.h>
#include<iostream>
#include<Utility.h>
using namespace tools;
using namespace std;
using namespace inventory_bl;
bool ItemNameAsKeyComparator::operator()(const char *left,const char *right)
{
if(Utility::iCompareStrings(left,right) < 0) return true;
return false;
}
#endif