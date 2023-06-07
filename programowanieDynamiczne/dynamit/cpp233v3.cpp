#include <bits/stdc++.h>
using namespace std;

const int mak = 3e5 + 15;
const int inf = 1e9 + 7;

int n, m;
int dp[mak];
int liczba_uzytych;

bool dynamit[mak];
vector<int>G[mak];

void wczytanie(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> dynamit[i];
	}

	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void dfs(int v, int odl, int p = -1){
	int Min = inf, Max = -inf;

	for(auto u: G[v]){
		if(u == p) continue;

		dfs(u, odl, v);
		Min = min(Min, dp[u]);
		Max = max(Max, dp[u]);
	}

	if(Min != inf && Min + Max > 0) dp[v] = Max - 1;
	else{
		if(Min < 0) dp[v] = Min - 1;
		else dp[v] = dynamit[v] ? -1 : 0;
	}

	if(dp[v] == -(odl + 1)){
		dp[v] = odl;
		liczba_uzytych++;
	}
}

bool sprawdzenie(int odl){
	liczba_uzytych = 0;

	dfs(1, odl);

	if(dp[1] < 0) liczba_uzytych++;

	return liczba_uzytych <= m;
}

int liczenie(){
	int l = 0, r = n; 

	while(l < r){
		int mid = (l + r) / 2;
		
		if(sprawdzenie(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}

	return (l + r) / 2;
}

int main(){
	wczytanie();
	cout << liczenie() << "\n";
}
