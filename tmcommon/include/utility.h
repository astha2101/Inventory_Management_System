#ifndef   __UTILITY_H 
#define   __UTILITY_H 1
namespace tools
{
class Utility
{
private:
Utility();
public:
static int getDigitsCount(int);
static int compareStrings(const char *left,const char *right);
static int iCompareStrings(const char *left,const char *right);
};
}
#endif