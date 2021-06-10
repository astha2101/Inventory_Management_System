#ifndef  __Item_cpp_inventory_bl
#define __Item_cpp_inventory_bl  1
#include<bl\Item.h>
#include<bl\bl.h>
#include<SerializedStream.h>	
#include<FileHandler.h>
#include<Utility.h>
#include<string.h>
using namespace tools;
using namespace ObjectIO;
using namespace inventory_bl;
Item::Item()
{
this->code=0;
this->name="";
this->category="";
}
Item::Item(int code,string name,__$$__BL_ENUMERATION category)
{
this->code=code;
this->name=name;
this->setCategory(category);
}
Item::Item(const Item &other)
{
this->code=other.code;
this->name=other.name;
this->category=other.category;
}
Item & Item::operator=(const Item &other)
{
this->code=other.code;
this->name=other.name;
this->category=other.category;
return *this;
}
void Item::setCode(int code)
{
this->code=code;
}
int Item::getCode()
{
return this->code;
}
void Item::setName(string name)
{
this->name=name;
}
const char * Item::get_name()
{
return this->name.c_str();
}
string  Item::getName()
{
return this->name;
}
void Item::setCategory(__$$__BL_ENUMERATION category)
{
if(category==RAW_MATERIAL) this->category="R";
else if(category==FINISHED_GOOD) this->category="F";
else if(category==CONSUMABLE) this->category="C";
else this->category="";
}
string Item::getCategory()
{
if(category=="R")
{
return "Raw Material";
}else
if(category=="F")
{
return "Finished Good";
}
else
if(category=="C")
{
return "Consumable";
}
else return "";
}
Item::~Item()
{
}

#endif