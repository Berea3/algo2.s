#include <fstream>
#include <cstring>
 
using namespace std;
 
ifstream cin("trie.in");
ofstream cout("trie.out");
 
struct Trie
{
    Trie *fii[30];
    int nrcuv;
    int nrpref;
    Trie()
    {
        for (int i=0;i<=26;i++)
        {
            fii[i]=nullptr;
            nrcuv=0;
            nrpref=0;
        }
    };
};
 
 
Trie *rad = new Trie();
 
void Add(char T[5000])
{
    int n=strlen(T);
    Trie *aux=rad;
    for (int i=0;i<n;i++)
    {
        if (aux->fii[T[i]-'a']==nullptr) aux->fii[T[i]-'a']=new Trie();
        aux=aux->fii[T[i]-'a'];
        aux->nrpref++;
        if (i==n-1) aux->nrcuv++;
    }
}
 
void Erase(char T[5000])
{
    int n=strlen(T);
    Trie *aux=rad;
    for (int i=0;i<n;i++)
    {
        aux=aux->fii[T[i]-'a'];
        if (aux==nullptr) return;
        aux->nrpref--;
        if (i==n-1) aux->nrcuv--;
    }
}
 
int Query1(char T[5000])
{
    int n=strlen(T);
    Trie *aux=rad;
    for (int i=0;i<n;i++)
    {
        aux=aux->fii[T[i]-'a'];
        if (aux==nullptr) return 0;
        if (i==n-1) return aux->nrcuv;
    }
}
 
int Query2(char T[5000])
{
    int n=strlen(T);
    Trie *aux=rad;
    int lung=0;
    for (int i=0;i<n;i++)
    {
        aux=aux->fii[T[i]-'a'];
        if (aux==nullptr) return lung;
        if (aux->nrpref>0) lung++;
    }
    return lung;
}
 
char t[5000];
 
int main()
{
    int x;
    while (cin>>x)
    {
        cin>>t;
        if (x==0) Add(t);
        if (x==1) Erase(t);
        if (x==2) cout<<Query1(t)<<"\n";
        if (x==3) cout<<Query2(t)<<"\n";
    }
}
