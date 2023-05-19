#include <iostream>                               // se cauta a in b

using namespace std;
const unsigned long long int base=1010012383;        // 29
const unsigned long long int mod=1010012359;           // 66.667
long long int hasha,hashb;    // astea sunt hash-urile
long long int plm,pow;
int i;
int c=0;                      // numarul de secvente gasite
string a,b;

int main()
{
    cin>>a>>b;
    pow=1;
    if (a.size()>b.size()) /// daca sirul a este mai lung ca b
    {
        cout<<0;
        return 0;
    }
    for (i=0;i<a.size();i++)
    {
        hasha=(hasha*base+a[i])%mod;  /// se face hashul pentru a
        hashb=(hashb*base+b[i])%mod;  /// se face hashul pentru b
        pow=(pow*base)%mod;           /// se face puterea
    }
    if (hasha==hashb) c++;
    for (i=1;i<=b.size()-a.size();i++)             /// scad dimensiunea sirului cautat pentru a nu ajunge in exteriorul sirului cautat, in dreapta
    {
        hashb=(hashb*base+b[i+a.size()-1])%mod;    /// se aduna hashul pentru litera urmatoare
        plm=(pow*b[i-1])%mod;
        hashb=(hashb-plm+mod)%mod;                 /// se scade pentru a face hashul fara litera de dinainte
        if (hasha==hashb) c++;
    }
    cout<<c<<"\n";
}
