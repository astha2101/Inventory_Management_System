#include <dl\ItemDL.h>
#include <dl\Item.h>
#include<dl\I_Item.h>
#include<forward_list>
#include<bl\Item.h>
#include<bl\I_Item.h>
#include<set>
#include<map>
#include<AbstractList>
#include<ListImplementation>
#include<List>
#include<bl\BLException.h>
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
map<string,I_Item *> itemsMap;
List<Item> getList()
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
__$__ITEM_CATEGORY category;
if(dlItem->getCategory()=='r') category=RAW_GOOD;
else if(dlItem->getCategory()=='f') category=FINISHED_GOOD;
else category=CONSUMABLE_GOOD;
item=new Item(dlItem->getCode(),dlItem->getName(),category);
itemsSet.insert(item);
itemsMap.insert(pair<string,I_Item *>(item->getName(),item));
++ii;
}
ListImplementation<I_Item *,Item,ItemComparator> *itemsList;
itemsList=new ListImplementation<I_Item *,Item,ItemComparator>(&itemsSet);
return List<Item>(itemsList);
}
Item  search(string name)
{
map<string,I_Item *>::iterator ii;
ii=itemsMap.find(name);
if(ii != itemsMap.end())
{
return *(Item *)(ii->second);
}
else
{
string message="Item does not exist ";
throw BLException(message);
}
}
int main()
{
try
{
List<Item> items=getList();
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
}
cout<<"-------------------------------"<<endl;
Item searchedItem=search("Pen");
cout<<searchedItem.getCode()<<","<<searchedItem.getName()<<","<<searchedItem.getCategory()<<endl;
}catch(BLException b)
{
cout<<b.getMessage()<<endl;
}
return 0;
}