#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, m;
int stopien[mak];
int przetworzony;
vector<int>G[mak];

queue<int>q;
vector<int>ans;

void liczenie()
{
	for(int i = 1; i <= n; i++)
	{
		if(stopien[i] == 0)
		{
			q.push(i);
			ans.push_back(i);
		}
	}

	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		przetworzony++;

		for(auto u: G[v])
		{
			stopien[u]--;
			if(stopien[u] == 0)
			{
				q.push(u);
				ans.push_back(u);
			}
		}
	}

	if(przetworzony != n)
	{
		cout << "IMPOSSIBLE\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;

		stopien[b]++;
		G[a].push_back(b);
	}

	liczenie();

	for(auto i: ans)
	{
		cout << i << " ";
	}
	cout << "\n";
}