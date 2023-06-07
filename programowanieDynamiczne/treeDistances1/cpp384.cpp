#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>G;
vector<int>fi, se, ans;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	G.resize(n + 1);
	fi.resize(n + 1);
	se.resize(n + 1);
	ans.resize(n + 1);

	int a, b;
	for(int i = 1; i < n; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void dfs1(int v, int p = 0){
	for(auto u: G[v]){
		if(u == p) continue;
		dfs1(u, v);

		if(fi[v] <= fi[u] + 1){
			se[v] = fi[v];
			fi[v] = fi[u] + 1;
		}
		else if(se[v] <= fi[u] + 1)
			se[v] = fi[u] + 1;
	}
}

void dfs2(int v, int p = 0, int ppath = 0){
	// printf("%d %d %d %d\n", v, fi[v], se[v], ppath);

	ans[v] = max(ppath, fi[v]);
	for(auto u: G[v]){
		if(u == p) continue;

		if(fi[u] + 1 == fi[v]) dfs2(u, v, max(se[v] + 1, ppath + 1));
		else dfs2(u, v, max(fi[v] + 1, ppath + 1));
	}
}

int main(){
	wczytaj();
	dfs1(1);
	dfs2(1);

	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}
