#include <bits/stdc++.h>
using namespace std;

const int mak = 50'005; 

int n, m;

vector<int>G[mak];
vector<int>Gt[mak];

vector<int>Gscc[mak];
int rozmiar_cyklu[mak];
set<int>node[mak];

bool odwiedzony[mak];
vector<int>kolejnosc;

int dp[mak];

int colour[mak], c = 0;

void wczytanie()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;

		G[a].push_back(b);
		Gt[b].push_back(a);
	}
}

void dfs(int v)
{
	odwiedzony[v] = true;

	for(auto u: G[v])
	{
		if(!odwiedzony[u])
		{
			dfs(u);
		}
	}

	kolejnosc.push_back(v);
}

void kolorowanie(int v)
{
	colour[v] = c;
	for(auto u: Gt[v])
	{
		if(!colour[u])
		{
			kolorowanie(u);
		}
	}
}

void make_scc()
{
	for(int i = 1; i <= n; i++)
	{
		if(!odwiedzony[i]) dfs(i);
	}

	reverse(kolejnosc.begin(), kolejnosc.end());

	for(auto u: kolejnosc)
	{
		if(!colour[u])
		{
			c++;
			kolorowanie(u);
		}
	}

	for(int i = 1; i <= n; i++)
	{
		rozmiar_cyklu[colour[i]]++;
		for(auto u: G[i])
		{
			auto it = node[colour[i]].find(u);
			if(colour[u] != colour[i] && it == node[colour[i]].end())
			{
				node[colour[i]].insert(u);
				Gscc[colour[i]].push_back(colour[u]);
			}
		}
	}
}

int drogi(int v)
{
	if(dp[v]) return dp[v];
	if(Gscc[v].size() == 0) return dp[v] = rozmiar_cyklu[v] - 1;

	dp[v] += rozmiar_cyklu[v] - 1;
	for(auto u: Gscc[v])
	{
		dp[v] += drogi(u) + 1;
	}

	return dp[v];
}

void liczenie_odleglosci()
{
	for(int i = 1; i <= c; i++)
	{
		drogi(i);
	}
}

void wypisanie()
{
	for(int i = 1; i <= n; i++)
	{
		cout << dp[colour[i]] << "\n";
	}
}

int main()
{
	wczytanie();
	make_scc();
	liczenie_odleglosci();
	wypisanie();
}