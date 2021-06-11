#include<SerializedStream.h>
#ifndef __SERIALIZABLE_H
#define __SERIALIZABLE_H 1
namespace ObjectIO
{
class Serializable
{
public:
virtual SerializedStream * Serialize()=0;
virtual void deSerialize(SerializedStream *)=0;
virtual void dispose(SerializedStream *)=0;
};
}
#endif