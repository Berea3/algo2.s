#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("kfib.in");
ofstream fout("kfib.out");
using Matrix = vector < vector < long long> >;
const long long mod=666013;
const long long k=2;

Matrix mult(Matrix A, Matrix B)
{
    Matrix res(k+1,vector<long long int>(k+1));    // initializare de vector
    for (long long int i=1;i<=k;i++)
    {
        for (long long int j=1;j<=k;j++)
        {
            for (long long int w=1;w<=k;w++) res[i][j]=(res[i][j]+A[i][w]*B[w][j])%mod;
        }
    }
    return res;
}

Matrix pow(Matrix A, long long int p)
{
    if (p==1) return A;
    if (p%2==1) return mult(A,pow(A,p-1));
    Matrix X=pow(A,p/2);
    return mult(X,X);
}

int main()
{
    long long int n;
    fin>>n;
    if (n==1 || n==2)
    {
        fout<<1;
        return 0;
    }
    Matrix T(k+1,vector<long long int> (k+1));
    T[1][1]=1;  T[1][2]=1;
    T[2][1]=1;  T[2][2]=0;
    T=pow(T,n-2);
    vector<long long int>f(3);
    f[1]=1;
    f[2]=1;
    long long int res=0;
    for (long long int i=1;i<=k;i++) res=(res+T[i][1]*f[i])%mod;
    fout<<res;
}
