#ifndef __SERIALIZED_STREAM_H
#define __SERIALIZED_STREAM_H 1
namespace ObjectIO
{
class SerializedStream
{
private:
unsigned int size;
const char * base;
public:
SerializedStream(const SerializedStream &other);
SerializedStream(const char *base, unsigned int size);
SerializedStream & operator=(const SerializedStream &other);
virtual ~SerializedStream();
const char * getBase();
unsigned int getSize(); 
};
}
#endif