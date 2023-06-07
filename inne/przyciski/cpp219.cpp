#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int>operacja;

void wczytywanie()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;	
	for(int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		operacja.push_back(x); 
	}
}

void liczenie()
{
	int minimum = 0;
	int maksimum = 0;
	vector<int>przycisk(n + 1);

	for(auto u: operacja)
	{
		if(u == n + 1)
		{
			minimum = maksimum;
		}
		else
		{
			if(przycisk[u] < minimum)
			{
				przycisk[u] = minimum + 1;
			}
			else
			{
				przycisk[u]++;
			}

			maksimum = max(maksimum, przycisk[u]);
		}
	}

	//wypisywanie
	for(int i = 1; i <= n; i++)
	{
		if(przycisk[i] < minimum) cout << minimum << " ";
		else cout << przycisk[i] << " "; 
	}
	cout << endl;
}

int main()
{
	wczytywanie();
	liczenie();
}
