//#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
const int maxn=1e2+2;
int n,m,x,y,z,k,i,j,maxi;
int d[maxn][maxn];                      // d[i][j] retine distanta minima de la nodul i la nodul j

ifstream cin("roy-floyd.in");
ofstream cout("roy-floyd.out");

int main()
{
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
        cin>>x>>y>>z;                                                               // sa-mi bag pula
        d[x][y]=z;
    }
    for (i=1;i<=n;i++) for (j=1;j<=n;j++)
    {
        if (i==j) d[i][j]==0;                                                       // distanta de la un nod la acelasi nod este 0
        else if (d[i][j]==0) d[i][j]=(1<<29);                                       // distanta de la un nod la altu se initializeaza cu ceva mare
    }
    for (k=1;k<=n;k++) for (i=1;i<=n;i++) for (j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);         // se determina distanta minima de la nodul i la nodul j
    maxi=(1<<25);
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (d[i][j]>maxi) cout<<-1<<" ";                                      // daca distanta a ramas prea mare inseamna ca nu s-a gasit un drum
            else cout<<d[i][j]<<" ";                                              // altfel se afiseaza distanta
        }
        cout<<"\n";
    }
}
