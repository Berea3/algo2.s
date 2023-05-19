#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
int n;
 
void next();
void get(int & x);

int main()
{
    freopen("parsare.in","r",stdin);
    get(n);
}
 
const int limit=20000000;
int r=limit-1;
char sir[limit];
bool semn=false;
 
void next()
{
    if (r++==limit) fread(sir,1,limit,stdin),r=0;
}
 
void get(int & x)
{
    x=0;
    semn=false;
    for (;sir[r]<'0' || sir[r]>'9';next()) if (sir[r]=='-') semn=true;
    for (x=0;sir[r]>='0' && sir[r]<='9';next()) x=x*10+sir[r]-'0';
    if (semn==true)
    {
        x=-x;
        semn=false;
        return;
    }
}