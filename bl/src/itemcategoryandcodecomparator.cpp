#ifndef __ItemCategoryAndCodeComparator_cpp
#define  __ItemCategoryAndCodeComparator_cpp 1
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<iostream>
#include<Utility.h>
#include<bl\ItemCategoryAndCodeComparator.h>
using namespace std;
using namespace tools;
using namespace inventory_bl;
bool ItemCategoryAndCodeComparator::operator()(I_Item *left,I_Item *right)
{
if(left->getCategory()>right->getCategory()) return false;
if(left->getCategory()<right->getCategory()) return true;
if(left->getCode()==0 || right->getCode()==0) return false;
if(left->getCode() < right->getCode()) return true;
return false;
}
#endif