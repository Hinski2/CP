#include <bits/stdc++.h>
using namespace std;

const int mak = 205;

int n;
bool przetworzony[mak];

vector<pair<int, int>>G[mak];
vector<pair<int, int>>powiazania;

void mst()
{
	priority_queue<pair<int, pair<int, int>>>q;

	for(auto u: G[1]) q.push({u.first, {1, u.second}});
	przetworzony[1] = true;

	while(!q.empty())
	{
		int s = q.top().first;
		int a = q.top().second.first;
		int b = q.top().second.second;
		q.pop();

		if(!przetworzony[b])
		{
			przetworzony[b] = true;
			powiazania.push_back({a, b});

			for(auto u: G[b])
			{
				if(!przetworzony[u.second])
				{
					q.push({u.first, {b, u.second}});
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			if(i != j)
			{
				G[i].push_back({-x, j});
			}
		}
	}

	//liczenie
	mst();

	for(int i = 0; i < powiazania.size(); i++)
	{
		if(powiazania[i].first > powiazania[i].second) swap(powiazania[i].first, powiazania[i].second);
	}

	sort(powiazania.begin(), powiazania.end());

	for(auto u: powiazania)
	{
		cout << u.first << " " << u.second << "\n";
	}
}