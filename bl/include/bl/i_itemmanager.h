#ifndef  __I_ItemManager_h_inventory_bl
#define  __I_ItemManager_h_inventory_bl 1
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<List>
#include<bl\BLException.h>
#include<bl\bl.h>
using namespace collections;
namespace inventory_bl
{
class I_ItemManager
{
public:
virtual void add(I_Item *item)=0;
virtual void update(I_Item *item)=0;
virtual void remove(int code)=0;
virtual Item getByCode(int code)=0;
virtual Item getByName(string name)=0;
virtual int getCount()=0;
virtual int getCountByCategory(__$$__BL_ENUMERATION category)=0;
virtual List<Item> getAll(__$$__BL_ENUMERATION orderBy=ITEM_NAME)=0;
virtual List<Item> getByCategory(__$$__BL_ENUMERATION category,__$$__BL_ENUMERATION orderBy=ITEM_NAME)=0;
virtual void removeAll()=0;
virtual void removeByCategory(__$$__BL_ENUMERATION category)=0;
virtual void removeByName(string name)=0; 
};
} 
#endif