#include <bits/stdc++.h>
using namespace std;

const int maksimum=1e5+15;

int n, m;
int idx=1, id[maksimum], low[maksimum], dp[maksimum];

bool visited[maksimum];
long long ans[maksimum];

vector<int>v[maksimum];

void dfs(int wierzcholek, int rodzic=-1)
{
	visited[wierzcholek]=true;

	vector<int>comperate;
	comperate.push_back(1);

	int above=0;

	id[wierzcholek]=idx;
	low[wierzcholek]=idx;
	idx++;

	for(auto i:v[wierzcholek])
	{
		if(i!=rodzic)
		{
			if(visited[i])
			{
				low[wierzcholek]=min(low[wierzcholek], id[i]);
			}
			else
			{
				dfs(i, wierzcholek);

				dp[wierzcholek] += dp[i]+1;
				low[wierzcholek]=min(low[wierzcholek], low[i]);

				if(low[i]>=id[wierzcholek])
				{
					comperate.push_back(dp[i]+1);
				}
				else
				{
					above+=dp[i]+1;
				}
			}
		}	
	}

	above+=n-(dp[wierzcholek]+1);
	comperate.push_back(above);

	for(auto j:comperate)
	{
		ans[wierzcholek]+= j * 1LL * (n-j);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m;

	for(int i=1;i<=m;i++)
	{
		int a, b;
		cin>>a>>b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<"\n";
	}
}