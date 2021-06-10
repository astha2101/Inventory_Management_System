#include <dl\ItemDL.h>
#include <dl\Item.h>
#include <dl\I_Item.h>
#include <dl\DLException.h>
using namespace inventory_dl;
int main()
{
ItemDL itemDL;
cout<<"Number of items"<<itemDL.getCount()<<endl;
return 0;
}
