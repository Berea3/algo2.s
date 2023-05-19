//#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
const int MAXN=1e5+5;
int ma,n;
int aint[4*MAXN],a[MAXN],d[4*MAXN];
vector<int>b;

ifstream cin("sclm2.in");
ofstream cout("sclm2.out");
void update(int nod,int l,int r,int poz,int x)
{
    if (l==r)
    {
        aint[nod]=x;
        return;
    }
    int mij=(l+r)>>1;
    if (poz<=mij) update(nod*2,l,mij,poz,x);
    else update(nod*2+1,mij+1,r,poz,x);
    aint[nod]=max(aint[nod*2],aint[nod*2+1]);
}

void query(int nod,int l,int r,int st,int dr)
{
    if (st<=l && dr>=r)
    {
        ma=max(ma,aint[nod]);
        return;
    }
    int mij=(l+r)>>1;
    if (st<=mij) query(nod*2,l,mij,st,dr);
    if (dr>mij) query(nod*2+1,mij+1,r,st,dr);
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for ( int i = 1; i <= n; ++i) a[i] = lower_bound(b.begin(),b.end(),a[i]) - b.begin() + 1;
    for (int i=1;i<=n;i++)
    {
        d[i]=1;
        ma=0;
        query(1,1,n,1,a[i]);
        d[i]=ma+1;
        update(1,1,n,a[i],d[i]);
    }
    int idk=0;
    ma=0;
    for (int i=1;i<=n;i++)
    {
        query(1,1,n,1,a[i]);
        idk=max(idk,ma);
    }
    cout<<ma;
}