#include <bits/stdc++.h>
using namespace std;

const int mak = 2e5 + 15;
const int maks = 2e5;
int n, m;

vector<pair<int, int>>primeG;

bool check(int mid)
{
	vector<int>G[mak];
	for(int i = 0; i < min(mid, m); i++)
	{
		G[primeG[i].first].push_back(primeG[i].second);
		G[primeG[i].second].push_back(primeG[i].first);
	}

	int licznik = 0;

	vector<bool>odwiedzony(mak, false);
	queue<int>q;

	q.push(1);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		if(!odwiedzony[v])
		{
			odwiedzony[v] = true;

			licznik++;
			if(licznik == n) return true;

			for(auto u: G[v])
			{
				if(!odwiedzony[u]) q.push(u);
			}
		}
	}

	return false;
}

void wBinarne()
{
	int l = 0, r = maks;
	int ans = -1;

	while(l <= r)
	{
		int mid = (l + r) / 2;

		if(check(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}

	if(ans == -1) cout << "NIE ISTNIEJE\n";
	else cout << ans << "\n";
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
		primeG.push_back({a, b});
	}

	wBinarne();
}