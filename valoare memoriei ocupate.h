#include <iostream>

using namespace std;
int v[54][54][54];

int main()
{
	// aceasta sursa va afisa cate memorie ocupa variabila v
	// se pune double pentru a afisa cu virgula
	// sezeof determina cata memorie ocupa variabila
	// se imparte de 2 ori la 1024 pentru a afisa valoare in mb
    cout<<(double)sizeof(v)/1024/1024;
}
