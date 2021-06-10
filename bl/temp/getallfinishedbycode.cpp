#include <dl\ItemDL.h>
#include <dl\Item.h>
#include<dl\I_Item.h>
#include<forward_list>
#include<bl\Item.h>
#include<bl\I_Item.h>
#include<set>
#include<AbstractList>
#include<ListImplementation>
#include<List>
#include<string.h>
#include<IndexOutOfBoundsException>
using namespace exceptions;
using namespace inventory_bl;
using namespace collections;
class ItemComparator
{
public:
bool operator()(I_Item *left,I_Item *right)
{
if(left->getCode() < right->getCode()) return true;
return false;
}
};
set<I_Item *,ItemComparator> itemsSet;
List<Item> getList(string getBycategory)
{
inventory_dl::ItemDL itemDl;
forward_list<inventory_dl::I_Item *> *items;
items=itemDl.getAll();
I_Item *item;
inventory_dl::I_Item *dlItem;
forward_list<inventory_dl::I_Item *>::iterator ii=items->begin();
while(ii!=items->end())
{
dlItem=*ii;
__$__ITEM_CATEGORY itemBlCategory;
if(dlItem->getCategory()=='r' && getBycategory=="R")
{
itemBlCategory=RAW_GOOD;
item=new Item(dlItem->getCode(),dlItem->getName(),itemBlCategory);
itemsSet.insert(item);
}
if(dlItem->getCategory()=='f' &&  getBycategory=="F")
{
itemBlCategory=FINISHED_GOOD;
item=new Item(dlItem->getCode(),dlItem->getName(),itemBlCategory);
itemsSet.insert(item);
}
if(dlItem->getCategory()=='c' &&  getBycategory=="C")
{
itemBlCategory=CONSUMABLE_GOOD;
item=new Item(dlItem->getCode(),dlItem->getName(),itemBlCategory);
itemsSet.insert(item);
}
++ii;
}
ListImplementation<I_Item *,Item,ItemComparator> *itemsList;
itemsList=new ListImplementation<I_Item *,Item,ItemComparator>(&itemsSet);
return List<Item>(itemsList);
}
int main()
{
List<Item> items=getList("F");
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
}
return 0;
}