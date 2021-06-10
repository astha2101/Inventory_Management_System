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
Item item1(0,"cotton",RAW_MATERIAL);
try
{
itemManager.add(&item1);
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
Item item2(0,"paint",CONSUMABLE);
try
{
itemManager.add(&item2);
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
Item item3(0,"PLASTIC",RAW_MATERIAL);
try
{
itemManager.add(&item3);
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
Item item4(0,"sofa",FINISHED_GOOD);
try
{
itemManager.add(&item4);
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
Item item5(0,"Glue",CONSUMABLE);
try
{
itemManager.add(&item5);
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
Item item6(0,"Table",FINISHED_GOOD);
try
{
itemManager.add(&item6);
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
Item item7(0,"nails",RAW_MATERIAL);
try
{
itemManager.add(&item7);
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
Item item8(0,"hammer",CONSUMABLE);
try
{
itemManager.add(&item8);
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
Item item9(0,"Cabin",FINISHED_GOOD);
try
{
itemManager.add(&item9);
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
Item item10(0,"chair",FINISHED_GOOD);
try
{
itemManager.add(&item10);
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
Item item11(0,"wood",RAW_MATERIAL);
try
{
itemManager.add(&item11);
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