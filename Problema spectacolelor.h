#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int n,i,x,y,c=1,last;

vector<pair<int,int> >v;

ifstream fin("spectacole.in");
ofstream fout("spectacole.out");

int main()
{
    fin>>n;
    for (i=1;i<=n;i++)
    {
        fin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort (v.begin(),v.end());
    last=v[0].second;
    for (i=1;i<=v.size();i++)
    {
        if (last<=v[i].first)
        {
            c++;
            last=v[i].second;
        }
        else if (last>v[i].second) last=v[i].second;
    }
    fout<<c;
}