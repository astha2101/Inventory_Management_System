#include <dl\ItemDL.h>
#include <dl\Item.h>
#include <dl\I_Item.h>
#include <dl\DLException.h>
using namespace inventory_dl;
#include<stdlib.h>
int main(int cnt,char *str[])
{
string name;
if(cnt!=2)
{
cout<<"Usage[TestItemDelete CodeOfItem]"<<endl;
return 0;
}

ItemDL itemDL;
try
{
itemDL.remove(atoi(str[1]));
cout<<"Item deleted with code as :"<<str[1]<<endl;
}catch(DLException dlException)
{
cout<<"Exception generated :"<<dlException.getMessage()<<endl;
}
return 0;
}