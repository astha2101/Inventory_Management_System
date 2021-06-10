#ifndef __ItemCategoryAndNameComparator_cpp
#define  __ItemCategoryAndNameComparator_cpp 1
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<iostream>
#include<bl\ItemCategoryAndNameComparator.h>
#include<Utility.h>
using namespace tools;
using namespace std;
using namespace inventory_bl;
bool  ItemCategoryAndNameComparator::operator()(I_Item *left,I_Item *right)
{
if(left->getCategory()<right->getCategory()) return true;
if(left->getCategory()>right->getCategory()) return false;
if(left->getName().length()==0 || right->getName().length()==0) return false;
if(Utility::iCompareStrings(left->getName().c_str(),right->getName().c_str()) < 0) return true;
return false;
}

#endif