#include <fstream>

using namespace std;
int n,k,i,j,t;

ifstream cin("combinari.in");
ofstream cout("combinari.out");

int main()
{
    cin>>n>>k;
    for (i=(1<<n)-1;i>=1;i--)
    {
        if (__builtin_popcount(i)==k)
        {
            for (j=n-1;j>=0;j--)
            {
                if ((i|(1<<j))==i) cout<<n-(j+1)+1<<" ";
            }
            cout<<"\n";
        }
    }
}