#include<Utility.h>
#ifndef  __Utlity_cpp
#define  __Utility_cpp
using namespace tools;
Utility::Utility()
{
}
int Utility::getDigitsCount(int number)
{
int dc=1;
if(number<0) number*=(-1);
while(number>9)
{
number/=10;
dc++;
}
return dc;
}
int Utility::compareStrings(const char *left,const char *right)
{
for(;*left && *right && *left==*right;left++,right++)
return *left-*right;
}
int Utility::iCompareStrings(const char *left,const char *right)
{
char lll,rrr;
while(*left && *right)
{
lll=(*left >=65 && *left<=90)?*left+32:*left;
rrr=(*right >=65 && *right<=90)?*right+32:*right;
if(lll != rrr) return lll-rrr;
left++;
right++;
}
return *left-*right;
}
#endif