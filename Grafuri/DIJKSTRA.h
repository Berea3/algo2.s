#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
const int MAXN=1e2+1;
int n,m,p,i,x,y,z,dx,v,dv;
int d[MAXN];
vector<pair<int,int> >g[MAXN];
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >q;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

void dijkstra()
{
    for (i=1;i<=n;i++) d[i]=(1<<30);
    q.push(make_pair(0,p));                 // primul element din coada retine distanta ca sa sorteza dupa distanta si al doilea retine nodul
    d[p]=0;
    while (q.size()>0)
    {
        x=q.top().second;                    // nodul
        dx=q.top().first;                    // distanta pana la nod
        if (dx!=d[x])                        // #optimizare
        {                                    // daca s-a gasit deja un drum atunci trecem mai departe
            q.pop();
            continue;
        }
        for (auto a:g[x])                    // se parcurg vecinii nodului
        {
            v=a.first;                       // vecinul nodului
            dv=a.second;                     // distanta de la nod la vecin
            if (d[v]>d[x]+dv)                // daca distanta e mai mica atunci se inlocuieste
            {
                d[v]=d[x]+dv;
                q.push(make_pair(d[v],v));
            }
        }
        q.pop();
    }
}

int main()
{
    fin>>n>>p;
    while (fin>>x>>y>>z) g[x].push_back(make_pair(y,z));
    dijkstra();
    for (i=1;i<=n;i++)
    {
        if (d[i]==(1<<30)) fout<<-1<<" ";
        else fout<<d[i]<<" ";
    }
}