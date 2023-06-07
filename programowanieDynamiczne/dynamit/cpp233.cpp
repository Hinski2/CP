#include <bits/stdc++.h>
using namespace std;

const int mak = 3e5 + 15;
const int inf = 1e9 + 7;

int n, m;
int liczba_podlozonych_dynamitow;
bool dynamit_komora[mak];

vector<int>G[mak];

void wczytanie()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> dynamit_komora[i];
	}
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void dfs(int v, vector<pair<int, int>>& dp, int mid, int p = -1)
{
	//odwołanie sie we wszystkich synach 
	for(auto u: G[v])
	{
		if(u != p)
		{
			dfs(u, dp, mid, v);
		}
	}

	if(G[v].size() == 1) //jeśli wierzchołek nie ma synów
	{
		if(dynamit_komora[v]) dp[v] = {0, inf};
		return;
	}

	//wierzcholek ma synów
	for(auto u: G[v])
	{
		if(u == p) continue;

		dp[v].second = min(dp[u].second + 1, dp[v].second);
		if(dp[u].first == 0 && dynamit_komora[u] && dp[u].first >= dp[v].first) dp[v].first = 1;
		else if(dp[u].first > dp[v].first) dp[v].first = dp[u].first + 1;
	}

	//ostateczen ustawienie wierzcholka
	if(dp[v].second == inf && dp[v].first >= mid)
	{
		liczba_podlozonych_dynamitow++;
		dp[v] = {0, 0};
	}
	else if(dp[v].second != inf && dp[v].first + dp[v].second > mid)
	{
		liczba_podlozonych_dynamitow++;
		dp[v] = {0, 0};
	}
}

bool sprawdzenie(int mid)
{
	liczba_podlozonych_dynamitow = 0;
	vector<pair<int, int>>dp(n + 1, {0, inf});

	dfs(1, dp, mid);

	if(liczba_podlozonych_dynamitow > m) return false;
	return true;
}

int wyszuiwanie_binarne()
{
	int l = 0, r = n, mid;

	while(l < r)
	{
		mid = (l + r) / 2;

		if(sprawdzenie(mid))
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}

	return l;
}

int main()
{
	wczytanie();
	cout << wyszuiwanie_binarne() << "\n";
}