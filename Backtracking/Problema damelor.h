#include <iostream>
#include <cmath>

using namespace std;
int n;
int a[15];

void afis()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (a[i]==j) cout<<"* ";
            else cout<<"- ";
        }
        cout<<"\n";
    }
    exit(0);
}

bool verif(int k)
{
    for (int i=1;i<k;i++) if (a[i]==a[k] || k-i==abs(a[k]-a[i])) return false;
    return true;
}

void backtracking(int k)
{
    for (int i=1;i<=n;i++)
    {
        a[k]=i;
        if (verif(k))
        {
            if (k==n) afis();
            else backtracking(k+1);
        }
    }
}

int main()
{
    cin>>n;
    backtracking(1);
}
