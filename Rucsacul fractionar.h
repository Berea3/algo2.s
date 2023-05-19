#include <iostream>
#include <algorithm>
#include <vector>
#define mp make_pair

using namespace std;
double n,gmax,x,y,i,gnow,val;
vector<pair<double,pair<double,double>> >v;

int main()
{
    cin>>n>>gmax;
    for (i=1;i<=n;i++)
    {
        cin>>x>>y;
        v.push_back(mp((y/x),mp(x,y)));
    }
    sort(v.begin(),v.end());
    for (i=v.size()-1;i>=0;i--)
    {
        if (gnow+v[i].second.first<=gmax)
        {
            gnow=gnow+v[i].second.first;
            val=val+v[i].second.second;
        }
        else
        {
            cout<<val+(gmax-gnow)*v[i].first;
            return 0;
        }
    }
    cout<<val;
}
