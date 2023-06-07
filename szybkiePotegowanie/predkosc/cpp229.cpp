#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int liczba_pytan;

ll power(ll n, ll x)
{
	if(x == 0) return 1LL;

	ll res = power(n, x / 2);
	res *= res;

	if(x % 2 == 0) return res;
	return res * n; 
}

ll zapytanie_roberta()
{
	cin >> liczba >> potega;

	return power(liczba, potega);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> liczba_pytan;
	while(liczba_pytan--)
	{
		cout << zapytanie_roberta() << "\n";
	}
}