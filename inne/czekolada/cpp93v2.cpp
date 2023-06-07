#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

vector<pair<long long, long long>>sprawdz;

void wyznaczenie_dziel_c()
{
	for(int i = 1; i <= sqrt(c); i++)
	{
		if(c % i == 0)
		{
			long long dz1 = i;
			long long dz2 = c / i;
 
			sprawdz.push_back({dz1, dz2 * d});
			sprawdz.push_back({dz2, dz1 * d});
		}
	}
}

void wyznaczenie_dziel_d()
{
	for(int i = 1; i <= sqrt(d); i++)
	{
		if(d % i == 0)
		{
			long long dz1 = i;
			long long dz2 = d / i;
 
			sprawdz.push_back({dz1, dz2 * c});
			sprawdz.push_back({dz2, dz1 * c});
		}
	}
}

void sprawdzenie()
{
	for(auto u: sprawdz) //dla x
	{
		if((u.first <= a && u.second <= b) || (u.first <= b && u.second <= a))
		{
			cout<<"TAK\n";
			return;
		}
	}
	cout<<"NIE\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin>>a>>b>>c>>d;

	wyznaczenie_dziel_c();
	wyznaczenie_dziel_d();

	sprawdzenie();
}