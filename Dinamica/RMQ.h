#include <fstream>        // rezolvare problema #1899 afisminime

using namespace std;
const int maxn=1e5+1;
int n,i,x,pow,m,y;
int r[17][maxn];
int l[maxn];          // vectorul pentru logaritm
int v[maxn];

ifstream cin("afisminime.in");
ofstream cout("afisminime.out");

void rmq()
{
    for (i=1;i<=n;i++) r[0][i]=v[i];     // 2^0 este unu, deci minimul pe intervalul i...i+1-1 este chiar elementul din vector
    for (i=2;i<=n;i++) l[i]=l[i/2]+1;    // se calculeaza logaritm de ordin doi din fiecare numar pana la n pentru a determina cea mai mare putere de 2 mai mica sau egala decat fiecare interval
    for (pow=1;pow<=16;pow++)
    {
        for (i=1;i<=n-(1<<pow)+1;i++)
        {
            if (r[pow-1][i]<r[pow-1][i+(1<<(pow-1))]) r[pow][i]=r[pow-1][i];                     // intervalul se dubleaza de fiecare data deci va fi i...j....j+j-i
            else r[pow][i]=r[pow-1][i+(1<<(pow-1))];                                             // din astea doua se ia intervalul cu minimul mai mic
        }
    }
}

// r[i][j] retine minimul pe intervalul j....j+2^i-1
// se pune minus 1 pentru ca r[i][j] retine minimul pe un intreval de lungime de putere de 2

int query()
{
    pow=l[y-x+1];
    return min(r[pow][x],r[pow][y-(1<<pow)+1]);
}

int main()
{
    cin>>n>>m;
    for (i=1;i<=n;i++) cin>>v[i];
    rmq();
    for (i=1;i<=m;i++)
    {
        cin>>x>>y;
        cout<<query()<<"\n";
    }
}
