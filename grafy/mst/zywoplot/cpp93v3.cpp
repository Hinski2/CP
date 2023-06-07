#include<bits/stdc++.h>
using namespace std;

const int maksimum = 1015;
int n, m;
int tuje = 0;

int x[maksimum][maksimum], y[maksimum][maksimum];
bool odwiedzony[maksimum][maksimum];

vector<pair<int, pair<int, int>>>G[maksimum][maksimum];

int color[maksimum][maksimum], c = 0;

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

int main()
{
    wczytywanie();
    link();
}