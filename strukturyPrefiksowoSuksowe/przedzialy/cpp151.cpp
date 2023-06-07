#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n;
int suma[mak];

bool jest[mak];

vector<pair<int, int>>przedzialy;

void put(int a, int b)
{
	suma[a]++;
	suma[b]--;
}

void zliczanie()
{
	int l = 0, akt = 0;

	for(int i = 1; i <= 1e6; i++)
	{
		akt += suma[i];

		if(akt)
		{
			if(!l)
			{
				l = i;
			}
		}
		else
		{
			if(l)
			{
				przedzialy.push_back({l, i});
				l = 0;
			}
			else if(jest[i])
			{
				przedzialy.push_back({i, i});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin>>n;

	for(int i = 1; i <= n; i++)
	{
		int a, b;
		cin>>a>>b;

		if(a == b) jest[b] = true;

		put(a, b);
	}

	//liczenie
	zliczanie();

	//wypisywanie
	for(auto u: przedzialy)
	{
		cout<<u.first<<" "<<u.second<<"\n";
	}
}