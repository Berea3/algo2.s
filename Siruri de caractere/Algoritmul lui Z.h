#include <iostream>
#include <vector>
using namespace std;
///int INT_MAX;

vector<int>zarray (vector<int>arr)
{
    int n=arr.size();
    vector<int>z(n);
    int r=0,l=0;
    for (int k = 1; k < n; k++)
    {
        if (k > r)
        {
            r=l=k;
            while (r<n && arr[r]==arr[r-l]) r++;
            z[k]=r-l;
            r--;
        }
        else
        {
            int k1=k-l;
            if (z[k1]<r-k+1) z[k]=z[k1];
            else
            {
                l=k;
                while (r<n && arr[r]==arr[r-l]) r++;
                z[k]=r-l;
                r--;
            }
        }
    }
    return z;
}

vector<int>mergearray (vector<int>A,vector<int>B)
{
    int n=A.size();
    int m=B.size();
    vector<int> z;
    vector<int>c(n+m+1);
    for (int i = 0; i < m; i++) c[i]=B[i];

    ///c[m] = INT_MAX;

    for (int i=0;i<n;i++) c[m+i+1]=A[i];
    z = zarray(c);
    return z;
}

int findzarray(vector<int>A,vector<int>B,int n)
{
    int flag=0;
    vector<int>z;
    z=mergearray(A, B);
    for (int i=0;i<z.size();i++)
    {
        if (z[i] == n-i)
        {
            return i;
        }
    }
    return z.size();
}

int main()
{
    vector<int>A,B;
    int n;
    cin>>n;
    for (int i=1,x;i<=n;i++)
    {
        cin>>x;
        B.push_back(x);
    }
    cout<<findzarray(A,B,n);
}
