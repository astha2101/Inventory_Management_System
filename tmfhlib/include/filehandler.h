#ifndef  __FileHandler_h
#define  __FileHandler_h 1
#include <Serializable.h>
#include <SerializedStream.h>
#include<iostream>
using namespace ObjectIO;
using namespace std;
class FileHandler
{
struct RowHeader
{
int recordSize;
};
FILE *file;
int _failed;
string fileName;
public:
FileHandler();
FileHandler(string fileName);
FileHandler(const FileHandler &other);
FileHandler & operator=(const FileHandler &other);
virtual ~FileHandler();
void open(string fileName);
void close();
void seek(int position);
int length();
void read(Serializable *serializable);
void write(Serializable *serializable);
int failed();
string getFileName();
int getPosition();
void setLength(int length);
};
#endif