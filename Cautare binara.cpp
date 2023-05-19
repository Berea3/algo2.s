#include <iostream>

using namespace std;
const int MAXN=25e3+5;
int n,m,x;
int v[MAXN];

bool binsearch(int x);
// acest program determina cate din cele m numere se gasesc in cele n numere

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>v[i];
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>x;
		if (binsearch(x)==true) cout<<1<<" ";
		else cout<<0<<" ";
	}
}

bool binsearch(int x) // cautarea binara
{
	int l=1,r=n,mid;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (x>v[mid]) l=mid+1;
		else if (x<v[mid]) r=mid-1;
		else if (x==v[mid]) break;
	}
	if (v[mid]==x) return true;
	else return false;
}
