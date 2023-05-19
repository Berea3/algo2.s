#include <fstream>
#include <cstdio>

using namespace std;
const int MAXN=1e3+5;
int n,mid,sizea,sizeb,i,j,k;
int v[MAXN],a[MAXN],b[MAXN];

ifstream cin("input.in");
ofstream cout("input.out");

void merges(int l,int r)
{
	//cout<<l<<" "<<r<<"\n";
	//printf("%d %d\n",l,r);
	if (l>=r) return;
	mid=(l+r)>>1;
	merges(l,mid);
	mid=(l+r)>>1;
	merges(mid+1,r);

	mid=(l+r)>>1;
	for (int i=l,t=1;i<=mid;i++,t++) a[t]=v[i];
	for (int i=mid+1,t=1;i<=r;i++,t++) b[t]=v[i];
	sizea=mid-l+1;
	sizeb=r-mid;
	int i=1,j=1,t=l;
	while (i<=sizea && j<=sizeb)
	{
		if (a[i]<b[j])
		{
			v[t]=a[i];
			i++;t++;
		}
		else
		{
			v[t]=b[j];
			j++;t++;
		}
	}
	while (i<=sizea)
	{
		v[t]=a[i];
		i++;t++;
	}
	while (i<=sizeb)
	{
		v[t]=b[j];
		j++;t++;
	}
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>v[i];
	merges(1,n);
	for (int i=1;i<=n;i++) cout<<v[i]<<" ";
}
