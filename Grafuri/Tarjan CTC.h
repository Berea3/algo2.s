#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
const int MAXN=1e5+55;
int n,m,i;
int niv,nrcomp;
int nivel[MAXN];        // nivelul la care se afla nodul
int l[MAXN];            // nivelul minim de care se agata nodul
bool iss[MAXN];         // daca nodul se afla la momentul actual in stiva
bool viz[MAXN];         // acest vector retine daca nodul a fost sau nu vizitat
vector<int>g[MAXN];     // graful
stack<int>s;            // stiva pentru tarjan
vector<int>ctc[MAXN];

void tarjan(int nod)
{
    iss[nod]=true;
    viz[nod]=true;
    s.push(nod);
    nivel[nod]=l[nod]=++niv;
    for (auto y:g[nod])
    {
        if (viz[y]==false)
        {
            tarjan(y);
            l[nod]=min(l[nod],l[y]);
        }
        else if (iss[y]==true) l[nod]=min(l[nod],l[y]);
    }
    if (nivel[nod]==l[nod])
    {
        nrcomp++;
        while (s.size()>0)
        {
            int y=s.top();
            s.pop();
            iss[y]=false;
            ctc[nrcomp].push_back(y);
            if (nod==y) break;
        }
    }
}



int main()
{
    int x,y;
    cin>>n>>m;
    for (i=1;i<=m;i++)        // se citeste graful
    {
        cin>>x>>y;
        g[x].push_back(y);
    }
    for (i=1;i<=n;i++) if (viz[i]==false) tarjan(i);
    for (i=1;i<=nrcomp;i++)
    {
        for (int j=0;j<ctc[i].size();j++) cout<<ctc[i][j]<<" ";
        cout<<"\n";
    }
}
