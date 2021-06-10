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
I_Item *vItem=NULL;
Item item(1023,"table",FINISHED_GOOD);
try
{
itemManager.update(&item);
}catch(BLException e)
{
map<__$$__BL_ENUMERATION,string> exceptions=e.getExceptions();
map<__$$__BL_ENUMERATION,string>::iterator iter=exceptions.begin();
while(iter!=exceptions.end())
{
cout<<(*iter).second<<endl;
++iter;
}
}
return 0;
}