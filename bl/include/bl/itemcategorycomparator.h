#ifndef __Item_Category_Comparator_h
#define  __Item_Category_Comparator_h 1
#include<bl\I_Item.h>
#include<bl\Item.h>
namespace inventory_bl
{
class ItemCategoryComparator
{
public:
bool operator()(I_Item *left,I_Item *right);
};
}
#endif