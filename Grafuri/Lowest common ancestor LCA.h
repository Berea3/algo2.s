#include <iostream>           // rezolvare problema lca infoarena
#include <fstream>
#include <vector>

using namespace std;
const int MAXN=2e5+5;
int n,i,c=1,m,x,y,pow,q;
int radacina;
int f[MAXN];                      // se retine prima oara cand s-a intalnit nodul in bfs
int l[MAXN];                      // vectorul pentru logaritm
int e[MAXN];                      // sirul euler
int nivel[MAXN];                  // nivelele nodurilor
int rmq[21][MAXN];                // matricea pentru algoritmul de rmq
bool fiu[MAXN];                   // se retine care nod are tata
bool viz[MAXN];                   // vectorul de vizita pentru dfs
vector<int>g[MAXN];

//ifstream cin("lca.in");
//ofstream cout("lca.out");

// cel mai apropiat stramos comun a doua noduri este nodul de nivel minim dintre primele aparitii ale nodurilor din query din reprezentarea euler a arborelui
// reprezentarea euler este ordinea in care se parcurg nodurile in dfs

void dfs(int x)
{
    e[c++]=x;                           // se face sirul euler
    f[x]=c-1;                           // se retine prima oara cand s-a intalnit nodul in bfs
    for (auto y:g[x])
    {
        if (viz[y]==false)
        {
            viz[y]=true;
            nivel[y]=nivel[x]+1;        // se determina
            dfs(y);
            e[c++]=x;                   // se face sirul euler
        }
    }
}

void Rmq()
{
    for (i=2;i<=2*n;i++) l[i]=l[i/2]+1;
    for (i=1;i<=2*n;i++) rmq[0][i]=e[i];
    for (int pow=1;pow<=20;pow++)
    {
        for (i=1;i<=2*n-(1<<pow)+1;i++)         // merge de la primu element pana la 2*n - puterea de 2 pentru ca sirul euler are lungime 2*n
        {
            if (nivel[rmq[pow-1][i]] < nivel[rmq[pow-1][i+(1<<(pow-1))]]) rmq[pow][i]=rmq[pow-1][i];
            else rmq[pow][i]=rmq[pow-1][i+(1<<(pow-1))];
        }
    }
}

int lca(int x,int y)
{
    x=f[x];
    y=f[y];
    if (x>y) swap(x,y);
    pow=l[y-x+1];
    if (nivel[rmq[pow][x]]<nivel[rmq[pow][y-(1<<pow)+1]]) return rmq[pow][x];
    else return rmq[pow][y-(1<<pow)+1];
}

int main()
{
    cin>>n>>q;
    radacina=1;
    for (i=2;i<=n;i++)                  // se face graful
    {
        cin>>x;
        g[x].push_back(i);
        fiu[i]=true;                    // se retine daca nodul are tata
    }
    /*for (i=1;i<=n;i++)                // in cazul in care cerinta nu spune care este radacina arborelui, atunci este determinata aici
    {
        if (fiu[i]==false)              // radacina este nodul fara nici un tata
        {
            radacina=i;
            break;
        }
    }*/
    dfs(radacina);
    Rmq();
    for (i=1;i<=q;i++)
    {
        cin>>x>>y;
        cout<<lca(x,y)<<"\n";
    }
}
