#include <iostream>

using namespace std;
const int MAXN=1e5+5;
int n,m;
int type,x,y;
int t[MAXN],h[MAXN];

int findroot(int nod);
void Union(int rot1,int rot2);

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        t[i]=i;
        h[i]=1;
    }
    for (int i=1;i<=m;i++)
    {
        cin>>type>>x>>y;
        if (type==1) if (findroot(x)!=findroot(y)) Union(findroot(x),findroot(y));      // daca nu sunt legate deja nodurile atunci se leaga
        if (type==2)
        {
            if (findroot(x)==findroot(y)) cout<<"DA"<<"\n";                      // daca au aceeasi radacina inseamna ca sunt in aceeasi componenta
            else cout<<"NU"<<"\n";
        }
    }
}

int findroot(int nod)
{
    if (t[nod]==nod) return nod;
    return t[nod]=findroot(t[nod]);
}

void Union(int rot1,int rot2)
{
    if (h[rot1]>h[rot2]) t[rot2]=rot1;                          // ala mai mic se leaga la ala mai mare pentru a nu creste nivelul
    else if (h[rot1]<h[rot2]) t[rot1]=rot2;
    else if (h[rot1]==h[rot2])
    {
        t[rot1]=rot2;
        h[rot2]++;
    }
}
