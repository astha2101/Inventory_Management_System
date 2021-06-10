#ifndef  __ItemManager_h
#define  __ItemManager_h 1
#include<bl\I_Item.h>
#include<bl\item.h>
#include<bl\I_ItemManager.h>
#include<bl\ItemCodeComparator.h>
#include<bl\ItemNameComparator.h>
#include<bl\ItemCategoryComparator.h>
#include<bl\ItemCategoryAndCodeComparator.h>
#include<bl\ItemCategoryAndNameComparator.h>
#include<bl\ItemNameAsKeyComparator.h>
#include<bl\BLException.h>
#include<bl\CategoryWiseList>
#include<bl\bl.h>
#include<set>
#include<map>
#include<List>
using namespace collections;
namespace inventory_bl
{
class ItemManager:public I_ItemManager
{
private:
map<int,I_Item *> itemCodeMap;
map<const char *,I_Item *,ItemNameAsKeyComparator> itemNameMap;
set<I_Item *,ItemNameComparator> nameWiseSet;
set<I_Item *,ItemCodeComparator> codeWiseSet;
multiset<I_Item *,ItemCategoryAndCodeComparator> codeWiseMultiSet;
multiset<I_Item *,ItemCategoryAndNameComparator> nameWiseMultiSet;
void populateDataStructures();
unsigned int numberOfConsumables;
unsigned numberOfRawMaterials;
unsigned int numberOfFinishedGoods;
public:
ItemManager();
ItemManager(const ItemManager &other);
ItemManager & operator=(const ItemManager &other);
virtual ~ItemManager();
void add(I_Item *item);
void update(I_Item *item);
void remove(int code);
Item getByCode(int code);
Item getByName(string name);
int getCount();
int getCountByCategory(__$$__BL_ENUMERATION category);
List<Item> getAll(__$$__BL_ENUMERATION orderBy=ITEM_NAME);
List<Item> getByCategory(__$$__BL_ENUMERATION category,__$$__BL_ENUMERATION orderBy=ITEM_NAME);
void removeAll();
void removeByCategory(__$$__BL_ENUMERATION category);
void removeByName(string name); 
};
}
#endif