#include <iostream>
#include <bitset>

using namespace std;
const int MAXN=1e7+5;
const int MAXM=1e7+1;
int n,c,x;
bitset<MAXN>b;
// acest program marcheaza toti b[i] cu i neprim cu true
// toti b[i] cu i prim vor fi false

int main()
{
    cin>>n;
    for (int i=4;i<=MAXM;i+=2) b[i]=true;
    for (int i=3;i<=MAXM;i+=2)
    {
        if (b[i]==false)
        {
            for (int j=i+i;j<=MAXM-i+1;j+=i) b[j]=true;
        }
    }
}