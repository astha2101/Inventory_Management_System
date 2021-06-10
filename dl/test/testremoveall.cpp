#include<dl\ItemDL.h>
#include<dl\Item.h>
#include<dl\I_Item.h>
#include<dl\DLException.h>
#include<forward_list>
using namespace inventory_dl;
int main()
{
ItemDL itemDL;
cout<<"Before removing:"<<itemDL.getCount()<<endl;
cout<<"Removing all items"<<endl;
itemDL.removeAll();
cout<<"After removing :"<<itemDL.getCount()<<endl;
return 0;
}