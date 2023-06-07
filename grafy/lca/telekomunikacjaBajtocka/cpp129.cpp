#include <bits/stdc++.h>
using namespace std;

const int mak = 50015;
const int LOG = 16;

int n, m;
int idx = 0, preOrder[mak], postOrder[mak];
int up[mak][LOG], dist[mak];

vector<int>G[mak];

void dp(int v)
{
	for(int i = 1; i < LOG; i++)
	{
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
}

void dfs(int v, int p = -1)
{
	preOrder[v] = idx++;
	up[v][0] = p;

	dp(v);

	for(auto u: G[v])
	{
		if(u != p)
		{
			dist[u] = dist[v] + 1;
			dfs(u, v);
		}
	}

	postOrder[v] = idx++;
}

int lca(int a, int b)
{
	if(dist[a] < dist[b]) swap(a, b); //dystans od a ma być większy

	//skok o różnice między wysokościami  
	int r = dist[a] - dist[b];
	for(int i = LOG - 1; i >= 0; i--)
	{
		if(r & (1 << i)) a = up[a][i];
	}

	if(a == b) return a; //jeśli a pokrywa się z b

	//skoki do miejsca idealnie przed lca
	for(int i = LOG - 1; i >= 0; i--)
	{
		if(up[a][i] != up[b][i])
		{
			a = up[a][i];
			b = up[b][i];
		}
	}

	return up[a][0];
}
void zapytanie(int a, int b, int w)
{
	if(a == w || b == w)
	{
		cout<<"TAK\n";
	}
	//oba się znajdują
	else if(preOrder[a] > preOrder[w] && preOrder[b] > preOrder[w] && postOrder[a] < postOrder[w] && postOrder[b] < postOrder[w])		
	{
		if(w == lca(a, b)) cout<<"TAK\n";
		else cout<<"NIE\n";
	}

	//tylko jeden się znajduje
	else if((preOrder[a] > preOrder[w] &&  postOrder[a] < postOrder[w]) || (preOrder[b] > preOrder[w] && postOrder[b] < postOrder[w]))	
	{
		cout<<"TAK\n";
	}

	//oba się nie znajdują
	else		
	{
		cout<<"NIE\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin>>n;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin>>a>>b;

		G[a].push_back(b);
		G[b].push_back(a);
	}

	//pre procesing
	dfs(0);

	//wczytywanie i odpowiadanie na zapytania 
	cin>>m;
	while(m--)
	{
		int a, b, w;
		cin>>a>>b>>w;
		zapytanie(a, b, w);
	}
}
