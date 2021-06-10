#include <dl\ItemDL.h>
#include <dl\Item.h>
#include <dl\I_Item.h>
#include <dl\DLException.h>
using namespace inventory_dl;
#include<stdlib.h>
int main(int cnt,char *str[])
{
string name;
if(cnt!=4)
{
cout<<"Usage[TestItemUpdate codeOfItem nameOfItem categoryOfItem]"<<endl;
return 0;
}
I_Item *item=new Item();
item->setCode(atoi(str[1]));
item->setName(str[2]);
item->setCategory(str[3][0]);
ItemDL itemDL;
try
{
itemDL.update(item);
cout<<"Item updated with code as :"<<item->getCode()<<endl;
}catch(DLException dlException)
{
cout<<"Exception generated :"<<dlException.getMessage()<<endl;
}
delete item;
return 0;
}