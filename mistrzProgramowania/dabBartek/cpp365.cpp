#include<bits/stdc++.h>
using namespace std;

int n, k, t;
int ans;
vector<int>hi;
vector<bool>sick;
vector<vector<int>>G;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k >> t;
	G.resize(n + 1);
	hi.resize(n + 1);
	sick.resize(n + 1);
	ans = n;

	int x, a, b;
	for(int i = 1; i <= k; i++){
		cin >> x;
		sick[x] = 1;
	}

	for(int i = 1; i < n; i++){
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void compute_hi(int v, int p = 0){
	hi[v] = 1;

	for(auto u: G[v]){
		if(u == p) continue;

		compute_hi(u, v);
		hi[v] += hi[u];
	}
}

void compute_ans(int v, int p = 0){
	for(auto u: G[v]){
		if(u == p) continue;

		if(sick[u])ans -= hi[u];
		else compute_ans(u, v);
	}
}

int main(){
	wczytaj();
	compute_hi(1);	
	
	compute_ans(1);
	cout << ans << '\n';
}