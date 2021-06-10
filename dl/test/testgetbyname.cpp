#include <dl\ItemDL.h>
#include <dl\Item.h>
#include <dl\DLException.h>
#include<forward_list>
#include<iostream>
#include<stdlib.h>
using namespace std;
using namespace inventory_dl;
int main(int cnt,const char *str[])
{
if(cnt!=2)
{
cout<<"Usage [Code]"<<endl;
return 0;
}
ItemDL itemDL;
I_Item *item=new Item();
try
{
item=itemDL.getByName(str[1]);
cout<<item->getCode()<<" ,"<<item->getName()<<","<<item->getCategory()<<endl; 
}catch(DLException dlexception)
{
cout<<dlexception.getMessage()<<endl;
}
return 0;
}