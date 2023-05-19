#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n,i,j;
vector<char>st;
string v;

int main()
{
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>v;
        for (j=0;j<v.size();j++)
        {
            if (v[j]=='{' or v[j]=='[' or v[j]=='(')
            {
                st.push_back(v[j]);
            }
            else if ( (v[j]=='}' or v[j]==']' or v[j]==')') and st.size()==0)
            {
                st.push_back(5);
                break;
            }
            else if (v[j]=='}' and st.back()=='{')
            {
                st.pop_back();
            }
            else if (v[j]==']' and st.back()=='[')
            {
                st.pop_back();
            }
            else if (v[j]==')' and st.back()=='(')
            {
                st.pop_back();
            }
            else if (st.back()=='{' and v[j]!='}')
            {
                break;
            }
            else if (st.back()=='[' and v[j]!=']')
            {
                break;
            }
            else if (st.back()=='(' and v[j]!=')')
            {
                break;
            }
        }
        if (st.size()==0) cout<<"YES";
        else cout<<"NO";
        st.clear();
    }
}
