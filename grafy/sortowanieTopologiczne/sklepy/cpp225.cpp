#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mak = 5e5 + 15;

int n;
int na_lewo[mak], na_prawo[mak];

int arr[mak], lvl[mak];
vector<int>G[mak];

ll wynik;
vector<int>kolej;

void wczytanie()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
	for(int i = 1; i < n; i++)
	{
		cin >> na_prawo[i];
	}
	for(int i = 2; i <= n; i++)
	{
		cin >> na_lewo[i];
	}
}

void sprawdzenie_oplacalnosci()
{
	for(int i = 2; i <= n; i++)
	{
		if(na_lewo[i] <= na_prawo[i - 1])
		{
			G[i].push_back(i - 1);
			lvl[i - 1]++;
			wynik += na_lewo[i];
		}
		else
		{
			G[i - 1].push_back(i);
			lvl[i]++;
			wynik += na_prawo[i - 1];
		}
	}
}

void sortowanie_topologiczne()
{
	queue<int>q;
	for(int i = 1; i <= n; i++)
	{
		if(lvl[i] == 0)
		{
			q.push(i);
			kolej.push_back(i);

			wynik += arr[i];
		}
	}

	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		for(auto u: G[v])
		{
			lvl[u]--;
			if(lvl[u] == 0)
			{
				q.push(u);
				kolej.push_back(u);
				wynik += arr[u];
			}
		}
	}
}

void wypisanie()
{
	cout << wynik << "\n";
	for(auto u: kolej)
	{
		cout << u << " ";
	}

}

int main()
{
	wczytanie();
	sprawdzenie_oplacalnosci();
	sortowanie_topologiczne();
	wypisanie();
}