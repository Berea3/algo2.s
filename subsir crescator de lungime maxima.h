#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN=1e3+1;
int n,i,j,maxi;
int v[MAXN],d[MAXN];

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) cin>>v[i];
    for (i=1;i<=n;i++)
    {
        maxi=0;
        for (j=1;j<i;j++)
        {
            if (v[j]<=v[i])
            {
                if (maxi<d[j])
                {
                    maxi=d[j];
                }
            }
        }
        d[i]=maxi+1;
    }
    maxi=0;
    for (i=1;i<=n;i++) maxi=max(maxi,d[i]);
    cout<<maxi;
}
