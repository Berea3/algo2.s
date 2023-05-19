#include <fstream>                // rezolvare permutari pbinfo

using namespace std;
int n;
int a[15],use[15];

ifstream cin("permutari.in");
ofstream cout("permutari.out");

void afisare()
{
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

bool verificare(int k)
{
    for (int i=1;i<k;i++) if (a[i]==a[k]) return false;
    return true;
}

void backtracking(int k)
{
    for (int i=1;i<=n;i++)
    {
        if (use[i]==false)
        {
            a[k]=i;
            use[i]=true;
            if (k==n) afisare();
            else backtracking(k+1);
            use[i]=false;
        }
    }
}

int main()
{
    cin>>n;
    backtracking(1);
}