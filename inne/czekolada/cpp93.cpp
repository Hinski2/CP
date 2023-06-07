#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

long long P;

vector<int>dziel_c;
vector<int>dziel_d;

vector<pair<long long, long long>>sprawdz;

void wyznaczenie_dziel_c()
{
	for(int i = 1; i <= sqrt(c); i++)
	{
		if(c % i == 0)
		{
			dziel_c.push_back(i);
			dziel_c.push_back(c / i);
		}
	}
}

void wyznaczenie_dziel_d()
{
	for(int i = 1; i <= sqrt(d); i++)
	{
		if(d % i == 0)
		{
			dziel_d.push_back(i);
			dziel_d.push_back(d / i);
		}
	}

}

void wyznaczenie_par()
{
	for(auto i: dziel_c)
	{
		for(auto j: dziel_d)
		{
			long long l1 = 1LL * i * j;
			long long l2 = 1LL * P / l1;

			sprawdz.push_back({l1, l2});
		}
	}
}

void sprawdzenie()
{
	for(auto u: sprawdz)
	{
		if((u.first <= a && u.second <= b) || (u.second <= a && u.first <= b))
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

	P = 1LL * c * d;

	wyznaczenie_dziel_c();
	wyznaczenie_dziel_d();

	wyznaczenie_par();

	sprawdzenie();
}