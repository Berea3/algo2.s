//#include <iostream>     // rezolvare ture infoarena
#include <fstream>
 
using namespace std;
const int MAXN=255;
long long int n,m,t,k;
long long int x,y;
long long int d[3][262150];
bool b[MAXN][MAXN];
 
ifstream cin("ture.in");
ofstream cout("ture.out");
 
int main()
{
    cin>>n>>m>>k;
    if (n<m)
    {
        swap(n,m);
        cin>>t;
        for (int i=1;i<=t;i++)
        {
            cin>>y>>x;
            b[x][y]=true;
        }
    }
    else
    {
        cin>>t;
        for (int i=1;i<=t;i++)
        {
            cin>>x>>y;
            b[x][y]=true;
        }
    }
    d[2][0]=1;
    d[1][0]=1;
    if (k>min(n,m))
    {
        cout<<0;
        exit(0);
    }
    for (long long int i=1;i<=n;i++)
    {
        for (long long int j=1;j<=(1<<m)-1;j++)
        {
            if (__builtin_popcount(j)<=k+1)
            {
                d[2][j]=d[1][j];
                for (t=1;t<=m;t++)
                {
                    x=(1<<(t-1));
                    if ((j|x)==j && b[i][t]==false)
                    {
                        d[2][j]+=d[1][j-x];
                    }
                }
            }
        }
        for (long long int j=1;j<=(1<<m);j++)
        {
            d[1][j]=d[2][j];
            d[2][j]=0;
        }
 
    }
    long long int sum=0;
    for (long long int j=1;j<=(1<<m)-1;j++) if (__builtin_popcount(j)==k) sum+=d[1][j];
    cout<<sum;
}