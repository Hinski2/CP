#include<bits/stdc++.h>
using namespace std;

const int maksimum = 1015;
int n, m;
int tuje = 0;

int x[maksimum][maksimum], y[maksimum][maksimum];
int ansX[maksimum][maksimum], ansY[maksimum][maksimum];

bool odwiedzony[maksimum][maksimum];

vector<pair<int, pair<int, int>>>G[maksimum][maksimum];

int color[maksimum][maksimum], c = 0;

set<int>jest;


void wczytywanie()
{
	cin>>m>>n;

	for(int yi = 1; yi < n ; yi++)
	{
		for(int xi = 1; xi <= m; xi++)
		{
			char z;
			cin>>z;

			if(z == 'C')
			{
				x[xi][yi] = -1;
			}
			else
			{
				x[xi][yi] = 0;
			}
		}
	}

	for(int yi = 1; yi < m; yi++)
	{
		for(int xi = 1; xi <= n; xi++)
		{
			char z;
			cin>>z;

			if(z == 'C')
			{
				y[xi][yi] = -1;

			}
			else
			{
				y[xi][yi] = 0;
			}
		}
	}

	for(int i = 1; i <= m ; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j < n) G[j][i].push_back({x[j][i], {j + 1, i}});
			if(i > 1) G[j][i].push_back({y[j][i - 1], {j, i - 1}});
			if(j > 1) G[j][i].push_back({x[j - 1][i], {j - 1, i}});
			if(i < m) G[j][i].push_back({y[j][i], {j, i + 1}});
		}
	}
}

void MST()
{
	priority_queue<pair<int, pair<int, int>>>q;

	q.push({0, {1, 1}});

	while(!q.empty())
	{
		int s = q.top().first;
		pair<int, int> v = {q.top().second.first, q.top().second.second};

		q.pop();

		if(odwiedzony[v.first][v.second] == false)
		{
			odwiedzony[v.first][v.second] = true;
			
			//przydzielanie koloru
			if(s == 0)
			{
				color[v.first][v.second] = c;
			}
			else
			{
				c++;
				color[v.first][v.second] = c;
			}

			for(auto u: G[v.first][v.second])
			{
				if(odwiedzony[u.second.first][u.second.second] == false)
				{
					q.push({u.first, {u.second.first, u.second.second}});
				}
			}
		}
	}
}

void solve()
{
	for(int i = 1; i < maksimum - 5; i++)
	{
		for(int j = 1; j < maksimum - 5; j++)
		{
			odwiedzony[i][j] = false;
		}
	}

	queue<pair<int, int>>q;
	jest.insert(0);

	q.push({1, 1});

	while(!q.empty())
	{
       int v1 = q.top().first;
	   int v2 = q.top().second;

		q.pop();

		if(!odwiedzony[v1][[v2]])
		{
			odwiedzony[v1][v2] = true;
			
		}
	}

}

int main()
{
	wczytywanie();

	MST(); //metodą Prima

	solve();

}