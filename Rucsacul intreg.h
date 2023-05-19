#include <fstream>
#include <algorithm>

using namespace std;
const int MAXN=1e4+5;
int n,i,g,G,maxi;
int d[MAXN],w[MAXN],p[MAXN];

ifstream cin("ruksak.in");
ofstream cout("ruksak.out");

int main()
{
    cin>>n>>G;
    for (i=1;i<=n;i++) cin>>w[i]>>p[i];
    for (i=1;i<=n;i++) for (g=G-w[i];g>=0;g--) if (d[g+w[i]]<d[g]+p[i]) d[g+w[i]]=d[g]+p[i];
    for (i=G;i>=0;i--) maxi=max(maxi,d[i]);
    cout<<maxi;
}
