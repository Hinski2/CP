#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;
const int inf = 1e9;

int rozne_samochody, maks_na_podlodze, liczba_operacji;
int na_podlodze[mak];
int kolejnosc[mak];

list<int>occ[mak];


void wczytanie()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> rozne_samochody >> maks_na_podlodze >> liczba_operacji;
	for(int i = 0; i < liczba_operacji; i++)
	{
		cin >> kolejnosc[i];

		occ[kolejnosc[i]].push_back(i);
	}

	for(int i = 1; i <= rozne_samochody; i++)
	{
		occ[i].push_back(inf);
		occ[i].pop_front();
	}
}

int liczenie()
{
	int ans = 0;
	int liczba_roznych_na_podlodze = 0;

	priority_queue<pair<int, int>>usun;

	for(int i = 0; i < liczba_operacji; i++)
	{
		int v = kolejnosc[i];
		int next = occ[v].front();
		occ[v].pop_front();

		//dodwanie nowego wierzcholka
		if(!na_podlodze[v])
		{
			na_podlodze[v] = 1;
			liczba_roznych_na_podlodze++;
			ans++;
		}
		else
		{
			na_podlodze[v]++;
		}

		usun.push({next, v});

		//usuwanie samochodzika
		if(liczba_roznych_na_podlodze > maks_na_podlodze)
		{
			int v_usun = usun.top().second;
			usun.pop();

			na_podlodze[v_usun]--;
			if(na_podlodze[v_usun] == 0) liczba_roznych_na_podlodze--;
		}
	}

	return ans;
}

int main()
{
	wczytanie();
	cout << liczenie() << "\n";
}