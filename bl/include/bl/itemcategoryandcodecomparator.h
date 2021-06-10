#ifndef __ItemCategoryAndCodeComparator_h
#define  __ItemCategoryAndCodeComparator_h 1
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<iostream>
using namespace std;
namespace inventory_bl
{
class ItemCategoryAndCodeComparator
{
public:
bool operator()(I_Item *left,I_Item *right);
};
}
#endif