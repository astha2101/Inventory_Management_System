#include <dl\ItemDL.h>
#include <dl\Item.h>
#include <dl\DLException.h>
#include<forward_list>
#include<iostream>
using namespace inventory_dl;
using namespace std;
int main()
{
ItemDL itemDL;
forward_list<I_Item *> *items;
items=itemDL.getAll();
forward_list<I_Item *>::iterator fi;
fi=items->begin();
while(fi!=items->end())
{
I_Item *item;
item=*fi;
cout<<item->getCode()<<" , "<<item->getName()<<","<<item->getCategory()<<endl;
++fi;
}
fi=items->begin();
while(fi!=items->end())
{
delete *fi;
++fi;
}
delete items;
return 0;
}