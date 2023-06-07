#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int idx = 1;

vector<bool> vis;
vector<int> low, pre, dp;
vector<ll> ans;
vector<vector<int>>G;

inline void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	pre.resize(n + 1);
	low.resize(n + 1);
	dp.resize(n + 1);
	ans.resize(n + 1);
	G.resize(n + 1);
	vis.resize(n + 1);

	int a, b;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void oblicz_low(int v, int p = 0){
	vis[v] = true;
	pre[v] = low[v] = idx++;

	int above = 0;
	vector<int>compare;
	compare.push_back(1);

	for(auto u: G[v]){
		if(u == p) continue;

		if(vis[u]) low[v] = min(low[v], pre[u]);
		else{
			oblicz_low(u, v);

			dp[v] += dp[u] + 1;
			low[v] = min(low[v], low[u]);

			if(low[u] >= pre[v])
				compare.push_back(dp[u] + 1);
			else
				above += dp[u] + 1;
		}
	}

	above += n - (dp[v] + 1);
	compare.push_back(above);


	for(auto u: compare)
		ans[v] += 1LL * u * (n - u);
}

void wypisz(){
	for(int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
}

int main(){
	wczytaj();
	oblicz_low(1);
	wypisz();
}