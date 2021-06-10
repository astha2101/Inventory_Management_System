#ifndef  __ItemDL_cpp_inventory_dl
#define  __ItemDL_cpp_inventory_dl 1
#include<dl\I_Item.h>
#include<dl\Item.h>
#include<iostream>
#include<forward_list>
#include <FileHandler.h>
#include <dl\ItemHeader.h>
#include <dl\DLException.h>
#include <dl\ItemDL.h>
#include<Utility.h>
#include<string.h>
#include<SerializedStream.h>
using namespace std;
using namespace inventory_dl;
using namespace ObjectIO;
using namespace tools;
string ItemDL::DATA_FILE="item.data";


void ItemDL::add(I_Item *item)
{
FileHandler fileHandler;
fileHandler.open(DATA_FILE);
ItemHeader itemHeader;
if(fileHandler.length()==0)
{
itemHeader.setNumberOfRecords(0);
itemHeader.setLastGeneratedCode(1000);
fileHandler.write(&itemHeader);
fileHandler.seek(0);
}
fileHandler.read(&itemHeader);
I_Item *vItem=new Item;
while(true)
{
fileHandler.read(vItem);
if(fileHandler.failed()) break;
if(stricmp(vItem->getName().c_str(),item->getName().c_str())==0)
{
delete vItem;
fileHandler.close();
string message="Item ";
message=message+item->getName();
message=message+" exists.";
throw DLException(message);
}
}
delete vItem;
int newCode=itemHeader.getLastGeneratedCode()+1;
itemHeader.setLastGeneratedCode(newCode);
itemHeader.setNumberOfRecords(itemHeader.getNumberOfRecords()+1);
item->setCode(newCode);
fileHandler.write(item);
fileHandler.seek(0);
fileHandler.write(&itemHeader);
fileHandler.close();
}



void ItemDL::update(I_Item *item)
{
FileHandler fh;
fh.open(DATA_FILE);
if(fh.length()==0)
{
fh.close();
string message="Item Code:";
message=message+to_string(item->getCode());
message=message+" does not exist.";
throw DLException(message);
}
ItemHeader header;
fh.read(&header);
if(header.getNumberOfRecords()==0)
{
fh.close();
string message="Item Code:";
message=message+to_string(item->getCode());
message=message+" does not exist.";
throw DLException(message);
}
Item vItem;
bool found=false;
while(1)
{
fh.read(&vItem);
if(fh.failed()) break;
if(vItem.getCode()==item->getCode())
{
found=true;
break;
}
}
if(!found)
{
fh.close();
string message="Item code:";
message=message+to_string(item->getCode());
message=message+" does not exist.";
throw DLException(message);
}
fh.seek(0);
fh.read(&header);
while(true)
{
fh.read(&vItem);
if(fh.failed()) break;
if(vItem.getCode()!=item->getCode() && stricmp(vItem.getName().c_str(),item->getName().c_str())==0)
{
fh.close();
string message="Item ";
message=message+item->getName();
message=message+" exists.";
throw DLException(message);
}
}
FileHandler tmpfh;
char *tmpName=tmpnam(NULL);
tmpfh.open(string(tmpName+1));
fh.seek(0);
fh.read(&header);
tmpfh.write(&header);
while(true)
{
fh.read(&vItem);
if(fh.failed()) break;
if(vItem.getCode()!=item->getCode())
{
tmpfh.write(&vItem);
}
else
{
tmpfh.write(item);
}
}
tmpfh.close();
fh.close();
::remove(DATA_FILE.c_str());
rename(tmpName+1,DATA_FILE.c_str());
}



void ItemDL::remove(int code)
{
FileHandler fh;
fh.open(DATA_FILE);
if(fh.length()==0)
{
fh.close();
string message="Item Code:";
message=message+to_string(code);
message=message+" does not exist.";
throw DLException(message);
}
ItemHeader header;
fh.read(&header);
if(header.getNumberOfRecords()==0)
{
fh.close();
string message="Item Code:";
message=message+to_string(code);
message=message+" does not exist.";
throw DLException(message);
}
Item vItem;
bool found=false;
while(1)
{
fh.read(&vItem);
if(fh.failed()) break;
if(vItem.getCode()==code)
{
found=true;
break;
}
}
if(!found)
{
fh.close();
string message="Item code:";
message=message+to_string(code);
message=message+" does not exist.";
throw DLException(message);
}
FileHandler tmpfh;
char *tmpName=tmpnam(NULL);
tmpfh.open(string(tmpName+1));
fh.seek(0);
fh.read(&header);
header.setNumberOfRecords(header.getNumberOfRecords()-1);
tmpfh.write(&header);
while(true)
{
fh.read(&vItem);
if(fh.failed()) break;
if(vItem.getCode()!=code)
{
tmpfh.write(&vItem);
}
}
tmpfh.close();
fh.close();
::remove(DATA_FILE.c_str());
rename(tmpName+1,DATA_FILE.c_str());
}

I_Item * ItemDL::getByCode(int code)
{
FileHandler fileHandler;
fileHandler.open(DATA_FILE);
if(fileHandler.length()==0)
{
fileHandler.close();
string message="Item Code:";
message=message+to_string(code);
message=message+" is invalid";
throw DLException(message);
}
ItemHeader itemHeader;
fileHandler.read(&itemHeader);
if(itemHeader.getNumberOfRecords()==0)
{
fileHandler.close();
string message="Item Code:";
message=message+to_string(code);
message=message+" is invalid";
throw DLException(message);
}
I_Item * vItem=new Item;
while(true)
{
fileHandler.read(vItem);
if(fileHandler.failed()) break;
if(vItem->getCode()==code)
{
fileHandler.close();
return vItem;
}
}
fileHandler.close();
delete vItem;
string message="Item Code:";
message=message+to_string(code);
message=message+" is invalid";
throw DLException(message);
}





I_Item *  ItemDL::getByName(string name)
{
FileHandler fileHandler;
fileHandler.open(DATA_FILE);
if(fileHandler.length()==0)
{
fileHandler.close();
string message="Item :";
message=message+name;
message=message+"is invalid";
throw DLException(message);
}
ItemHeader itemHeader;
fileHandler.read(&itemHeader);
if(itemHeader.getNumberOfRecords()==0)
{
fileHandler.close();
fileHandler.close();
string message="Item :";
message=message+name;
message=message+"is invalid";
throw DLException(message);
}
I_Item * vItem=new Item;
while(true)
{
fileHandler.read(vItem);
if(fileHandler.failed()) break;
if(stricmp(vItem->getName().c_str(),name.c_str())==0)
{
fileHandler.close();
return vItem;
}
}
fileHandler.close();
string message="Item :";
message=message+name;
message=message+"is invalid";
throw DLException(message);
}





forward_list<I_Item *> * ItemDL::getAll()
{
forward_list<I_Item *> *items;
items=new forward_list<I_Item *>;
FileHandler fileHandler;
fileHandler.open(DATA_FILE);
if(fileHandler.length()==0)
{
fileHandler.close();
return items;
}
ItemHeader itemHeader;
fileHandler.read(&itemHeader);
if(itemHeader.getNumberOfRecords()==0)
{
fileHandler.close();
return items;
}
Item *item;
forward_list<I_Item *>::iterator fi;
fi=items->before_begin();
while(true)
{
item=new Item;
fileHandler.read(item);
if(fileHandler.failed())
{
delete item;
break;
}

items->insert_after(fi,item);
++fi;
}
fileHandler.close();
return items;
}





int ItemDL::getCount()
{
FileHandler fh;
fh.open(DATA_FILE);
if(fh.length()==0)
{
fh.close();
return 0;
}
ItemHeader header;
fh.read(&header);
fh.close();
return header.getNumberOfRecords();
}


void ItemDL::removeAll()
{
FileHandler fh;
fh.open(DATA_FILE);
if(fh.length()==0)
{
fh.close();
return;
}
ItemHeader itemHeader;
fh.read(&itemHeader);
fh.close();
::remove(DATA_FILE.c_str());
fh.open(DATA_FILE);
itemHeader.setNumberOfRecords(0);
fh.write(&itemHeader);
fh.close();
}
#endif