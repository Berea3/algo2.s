#include <iostream>

using namespace std;
const int MAXN=1e1+5;
int n,m;
int a[MAXN][MAXN];
pair<int,int>d[8];

void mort()
{
    d[0].first=-2;
    d[0].second=-1;
    d[1].first=-1;
    d[1].second=-2;
    d[2].first=1;
    d[2].second=-2;
    d[3].first=2;
    d[3].second=-1;
    d[4].first=2;
    d[4].second=1;
    d[5].first=1;
    d[5].second=2;
    d[6].first=-1;
    d[6].second=2;
    d[7].first=-2;
    d[7].second=1;
}

void afis()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++) cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n\n";
}

void backtracking(int i,int j,int poz)
{
    a[i][j]=poz;
    if (poz==n*m) afis();
    else for (int t=0;t<=7;t++)
    {
        int x=i+d[t].first;
        int y=j+d[t].second;
        if (x>=1 && x<=n && y>=1 && y<=m && a[x][y]==0)
        {
            backtracking(x,y,poz+1);
            a[x][y]=0;
        }

    }
}

int main()
{
    cin>>n>>m;
    mort();
    backtracking(1,1,1);
}
