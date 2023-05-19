// black jack
#include <iostream>

using namespace std;
const int MAXN=20;
int n=14,x,y;
int sum,runcount,truecount;
int v[MAXN];
bool as;

void init()
{
    for (int i=2;i<=n;i++) v[i]=4*x;
}

void add(int y)
{
    if (y>=2 && y<=10) sum+=y;
    if (y==11)
    {
        as=true;
        sum+=1;
    }
    if (y>=12 && y<=14) sum+=10;
}

double cardchance()
{
    int total=0,good=0,bad=0;
    for (int i=2;i<=10;i++)         // se calculeaza pentru numere
    {
        if (sum+i<=21) good+=v[i];
        else bad+=v[i];
        total+=v[i];
    }
    for (int i=12;i<=14;i++)         // se calculeaza pentru j q k
    {
        if (sum+10<=21) good+=v[i];
        else bad+=v[i];
        total+=v[i];
    }
    if (sum+1<=21) good+=v[11];    // se calculeaza pentru valoarea 1 de la as
    if (sum+11<=21) good+=v[11];   // se calculeaza pentru valoarea 11 de la as
    total+=v[11];
    return (double)total/100*good;
}

double winchance()
{
    x=0;
    for (int i=2;i<=n;i++) x+=v[i];
    return (double) runcount/(x/52);
}

int main()
{
    cout<<"Nr. pachete:";
    cin>>x;
    init();
    while (true)
    {
        cin>>x>>y;
        if (y>=2 && y<=14)
        {
            v[y]--;
            if (x==true) add(y);
            if (y>=2 && y<=6) runcount++;
            if (y>=10 && y<=14) runcount--;
        }
        if (y==15)
        {
            sum=0;
            as=false;
            cout<<winchance();
        }
        if (y==16) cout<<cardchance();
    }
}
