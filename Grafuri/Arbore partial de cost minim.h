#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN=4e5+5;
int n,m;
long long int s;
int t[MAXN],h[MAXN];
struct muchie{
    int x;int y;int cost;
};
muchie muc[MAXN];
vector<pair<int,int> >ans;

bool cmp(muchie x,muchie y);
int findroot(int nod);
void Union(int rot1,int rot2);

ifstream cin("kruskal.in");
ofstream cout("kruskal.out");

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        t[i]=i;
        h[i]=1;
    }
    for (int i=1;i<=m;i++) cin>>muc[i].x>>muc[i].y>>muc[i].cost;
    sort(muc+1,muc+m+1,cmp);
    for (int i=1;i<=m;i++)
    {
        if (findroot(muc[i].x)!=findroot(muc[i].y))
        {
            Union(findroot(muc[i].x),findroot(muc[i].y));
            s+=muc[i].cost;
            ans.push_back(make_pair(muc[i].x,muc[i].y));
        }
    }
    cout<<s<<"\n";
    for (int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
}

bool cmp(muchie x,muchie y)
{
    return x.cost<y.cost;
}

int findroot(int nod)
{
    if (t[nod]==nod) return nod;
    return t[nod]=findroot(t[nod]);
}

void Union(int rot1,int rot2)
{
    if (h[rot1]>h[rot2]) t[rot2]=rot1;
    else if (h[rot1]<h[rot2]) t[rot1]=rot2;
    else if (h[rot1]==h[rot2])
    {
        t[rot1]=rot2;
        h[rot2]++;
    }
}
