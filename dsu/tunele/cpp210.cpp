#include <bits/stdc++.h>
using namespace std;

const int mak = 2e5 + 15;
const int nak = 1e5 + 15;

int n, m, k;
int r[nak], r_size[nak];

pair<int, int>node[mak];

int find(int v)
{
	if(v == r[v]) return v;
	return r[v] = find(r[v]);
}

void join(int a, int b, int &liczba_spojnych)
{
	if(r[find(a)] == r[find(b)]) return; //wierzcholki są w jednej spójnej 

	//trzeba połaczyć spójne
	liczba_spojnych--;
	if(r_size[a] < r_size[b]) swap(a, b);
	r_size[a] += r_size[b];
	r[find(b)] = r[find(a)];
}

int liczenie()
{
	int liczba_spojnych = n;
	for(int i = m; i >= 1; i--)
	{
		join(node[i].first, node[i].second, liczba_spojnych);
		if(liczba_spojnych < k) return i + 1;
	}

	return 0;
}

void ustawienie()
{
	for(int i = 1; i <= n; i++)
	{
		r[i] = i;
		r_size[i] = 1;
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		node[i] = {a, b};
	}

	//liczenie
	ustawienie();
	cout << liczenie() << "\n";
}