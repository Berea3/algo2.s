#include <fstream>

using namespace std;
const int MAXN=1e5+5;
int mini,n,m,i,x,tip,y;
int aint[4*MAXN];

ifstream cin("aemi.in");
ofstream cout("aemi.out");

//nod tine nivelul
// l si r tin intervalul
// poz este pozitia pe care se actualizeaza
// x este numarul cu care se actualizeaza
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
    aint [nod]=min(aint[nod*2],aint[nod*2+1]);
}

void query(int nod,int l,int r,int st,int dr)      // l si r este intervalul curent
{                                                 // l si e este cuprins de st dr
    if (st<=l && dr>=r)
    {
        mini=min(mini,aint[nod]);
        return;
    }
    int mij=(l+r)>>1;
    if (st<=mij) query(nod*2,l,mij,st,dr);
    if (dr>mij) query(nod*2+1,mij+1,r,st,dr);
}

int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>x;
        update(1,1,n,i,x);
    }
    cin>>m;
    for (i=1;i<=m;i++)
    {
        cin>>tip>>x>>y;
        if (tip==1)
        {
            mini=(1<<30);                       // x si y este intervalul pe care se cauta minimul
            query(1,1,n,x,y);
            cout<<mini<<"\n";
        }
        if (tip==2) update(1,1,n,x,y);
    }
}
