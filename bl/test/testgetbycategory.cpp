#include<List>
#include<bl\BLException.h>
#include<IndexOutOfBoundsException>
#include<bl\ItemManager.h>
#include<bl\Item.h>
#include<bl\bl.h>
using namespace exceptions;
using namespace inventory_bl;
using namespace collections;
int main()
{
ItemManager itemManager;
__$$__BL_ENUMERATION orderBy=ITEM_NAME;
__$$__BL_ENUMERATION category=CONSUMABLE;
List<Item> items=itemManager.getByCategory(category,orderBy);
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
}
cout<<"------------------------------------------"<<endl;
orderBy=ITEM_NAME;
category=RAW_MATERIAL;
items=itemManager.getByCategory(category,orderBy);
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
}
cout<<"------------------------------------------"<<endl;
orderBy=ITEM_NAME;
category=FINISHED_GOOD;
items=itemManager.getByCategory(category,orderBy);
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
}
cout<<"------------------------------------------"<<endl;
orderBy=ITEM_CODE;
category=RAW_MATERIAL;
items=itemManager.getByCategory(category,orderBy);
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
}
cout<<"------------------------------------------"<<endl;
orderBy=ITEM_CODE;
category=FINISHED_GOOD;
items=itemManager.getByCategory(category,orderBy);
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
}
cout<<"------------------------------------------"<<endl;
orderBy=ITEM_CODE;
category=CONSUMABLE;
items=itemManager.getByCategory(category,orderBy);
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
}
return 0;
}