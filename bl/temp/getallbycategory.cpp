#include <dl\ItemDL.h>
#include <dl\Item.h>
#include<dl\I_Item.h>
#include<forward_list>
#include<bl\Item.h>
#include<bl\I_Item.h>
#include<set>
#include<utility>
#include<AbstractList>
#include<ListImplementation1>
#include<List>
#include<IndexOutOfBoundsException>
#include<string>
using namespace exceptions;
using namespace inventory_bl;
using namespace collections;
class ItemComparator
{
public:
bool operator()(pair<string,I_Item *> *left,pair<string,I_Item *> *right)
{
if(stricmp(left->first.c_str(),right->first.c_str()) < 0) return true; 
if(stricmp(left->first.c_str(),right->first.c_str()) == 0) 
{
if(left->second->getCode() < right->second->getCode()) return true;
else return false;
}
return false;
}
};
multiset<pair<string,I_Item *> *,ItemComparator> itemsSet;
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
pair<string,I_Item *> *c=new pair<string,I_Item *>(item->getCategory(),item);
itemsSet.insert(c);
++ii;
}
ListImplementation1<I_Item *,Item,ItemComparator> *itemsList;
itemsList=new ListImplementation1<I_Item *,Item,ItemComparator>(&itemsSet);
return List<Item>(itemsList);
}
int main()
{
List<Item> items=getList();
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
	}
return 0;
}