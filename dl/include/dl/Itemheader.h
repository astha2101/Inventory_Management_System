#ifndef  __ItemHeader_h_inventory_dl
#define  __ItemHeader_h_inventory_dl 1
#include<Serializable.h>
#include<iostream>
using namespace std;
using namespace ObjectIO;
namespace inventory_dl
{
class ItemHeader:public Serializable
{
private:
unsigned int numberOfRecords;
unsigned int  lastGeneratedCode;
public:
ItemHeader();
ItemHeader(unsigned int numberOfRecords,unsigned int lastGeneratedCode);
ItemHeader(const ItemHeader &other);
ItemHeader & operator=(const ItemHeader &other);
virtual ~ItemHeader();
void setNumberOfRecords(unsigned int numberOfRecords);
unsigned int getNumberOfRecords();
void setLastGeneratedCode(unsigned int lastGeneratedCode);
unsigned int getLastGeneratedCode();
SerializedStream * Serialize();
void deSerialize(SerializedStream *stream);
void dispose(SerializedStream *stream);
unsigned int getStreamSize();
};
}
#endif