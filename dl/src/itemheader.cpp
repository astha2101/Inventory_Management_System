#ifndef  __ItemHeader_cpp_inventory_dl 
#define  __ItemHeader_cpp_inventory_dl 1
#include<dl\ItemHeader.h>
#include<Serializable.h>
#include<SerializedStream.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
using namespace ObjectIO;
using namespace inventory_dl;
ItemHeader::ItemHeader()
{
this->numberOfRecords=0;
this->lastGeneratedCode=0;
}
ItemHeader::ItemHeader(unsigned int numberOfRecords,unsigned int lastGeneratedCode)
{
this->numberOfRecords=numberOfRecords;
this->lastGeneratedCode=lastGeneratedCode;
}
ItemHeader::ItemHeader(const ItemHeader &other)
{
this->numberOfRecords=other.numberOfRecords;
this->lastGeneratedCode=other.lastGeneratedCode;
}
ItemHeader & ItemHeader::operator=(const ItemHeader &other)
{
this->numberOfRecords=other.numberOfRecords;
this->lastGeneratedCode=other.lastGeneratedCode;
return *this;
}
ItemHeader::~ItemHeader()
{
}
void ItemHeader::setNumberOfRecords(unsigned int numberOfRecords)
{
this->numberOfRecords=numberOfRecords;
}
unsigned int ItemHeader::getNumberOfRecords()
{
return this->numberOfRecords;
}
void ItemHeader::setLastGeneratedCode(unsigned int lastGeneratedCode)
{
this->lastGeneratedCode=lastGeneratedCode;
}
unsigned int ItemHeader::getLastGeneratedCode()
{
return this->lastGeneratedCode;
}
SerializedStream * ItemHeader::Serialize()
{
char *str=new char[22];
sprintf(str,"%10d",this->numberOfRecords);
sprintf(str+11,"%10d",this->lastGeneratedCode);
return new SerializedStream(str,22);
}
void ItemHeader::deSerialize(SerializedStream *stream)
{
const char *str=stream->getBase();
while(*str==' ') str++;
this->numberOfRecords=atoi(str);
while(*str!='\0') str++;
str++;
while(*str==' ') str++;
this->lastGeneratedCode=atoi(str);
}
void ItemHeader::dispose(SerializedStream *stream)
{
const char *ptr=stream->getBase();
delete []ptr;
delete stream;
}
unsigned int ItemHeader::getStreamSize()
{
return 22;
}
#endif