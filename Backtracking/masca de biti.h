//#include <iostream>    // rezolvare adunscad pbinfo
#include <vector>
#include <fstream>

using namespace std;
int n,m,i,j;
int x,sum,sim;
int v[30];
vector<char>s;
vector<char>si;

ifstream cin("adunscad.in");
ofstream cout("adunscad.out");

int main()
{
    cin>>m>>n;
    for (i=1;i<=n;i++) cin>>v[i];
    for (i=0;i<=(((1<<n)-1)>>1);i++)
    {
        sum=0;
        for (j=0;j<n;j++)
        {
            x=(1<<j);
            if ((x|i)==i)
            {
                sum+=v[j+1];
                s.push_back('+');
            }
            else
            {
                sum-=v[j+1];
                s.push_back('-');
            }
        }
        if (sum==m)
        {
            for (j=0;j<s.size();j++)
            {
                if (j==0)
                {
                    if (s[j]=='+') cout<<v[j+1];
                    else cout<<s[j]<<v[j+1];
                }
                else cout<<s[j]<<v[j+1];
            }
            cout<<"\n";
            exit(0);
        }
        else if (-sum==m)
        {
            for (j=0;j<s.size();j++)
            {
                if (j==0)
                {
                    if (s[j]=='+') cout<<"-"<<v[j+1];
                    else cout<<v[j+1];
                }
                else
                {
                    if (s[j]=='+') cout<<"-"<<v[j+1];
                    else cout<<"+"<<v[j+1];
                }
            }
            cout<<"\n";
            exit(0);
        }
        s.resize(0);
    }
    cout<<0;
}
