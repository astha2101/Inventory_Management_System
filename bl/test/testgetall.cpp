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
List<Item> items=itemManager.getAll(orderBy);
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
}
cout<<"------------------------------------------"<<endl;;
orderBy=ITEM_CODE;
items=itemManager.getAll(orderBy);
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
}
cout<<"---------------------------"<<endl;
orderBy=CATEGORY_AND_CODE;
items=itemManager.getAll(orderBy);
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
}
cout<<"---------------------------------"<<endl;
orderBy=CATEGORY_AND_NAME;
items=itemManager.getAll(orderBy);
for(int i=0;i<items.getSize();i++)
{
Item item=items.get(i);
cout<<item.getCode()<<","<<item.getName()<<","<<item.getCategory()<<endl;
}
cout<<"---------------------------------"<<endl;
cout<<"Number of Elements :"<<itemManager.getCount()<<endl;
cout<<"Number of Raw Materials :"<<itemManager.getCountByCategory(RAW_MATERIAL)<<endl;
cout<<"Number of Finished goods :"<<itemManager.getCountByCategory(FINISHED_GOOD)<<endl;
cout<<"Number of Consumables :"<<itemManager.getCountByCategory(CONSUMABLE)<<endl;
return 0;
}