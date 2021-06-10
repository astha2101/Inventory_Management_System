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
try
{
itemManager.removeByName("screwdriver");
itemManager.removeByName("brush");
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