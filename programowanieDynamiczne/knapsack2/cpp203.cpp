#include <bits/stdc++.h>
using namespace std;

const int mak = 1e3 + 1;

int n, pojemnoscPlecaka;
int waga[101], wartosc[101];

unordered_map<int, int>m1;
unordered_map<int, int>m2;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> n >> pojemnoscPlecaka;
	for(int i = 1; i <= n; i++)
	{
		cin >> waga[i] >> wartosc[i];  
	}

	//liczenie
	m1[0] = 0;
	m2[0] = 0;

	for(int i = 1; i <= n; i++)
	{
		for(auto u: m1)
		{
			if(u.second + waga[i] > pojemnoscPlecaka) continue;
			
			auto it = m1.find(u.first + wartosc[i]);
			if(it == m1.end())
			{
				m2[u.first + wartosc[i]] = waga[i] + u.second;
			}
			else
			{
				m2[u.first + wartosc[i]] = min(m1[u.first + wartosc[i]], u.second + waga[i]);
			}
		}

		m1 = m2;
	}

	//wypisanie wyniku
	int ans = 0;
	for(auto u: m1)
	{
		ans = max(ans, u.first);
	}

	cout << ans << "\n";
}
