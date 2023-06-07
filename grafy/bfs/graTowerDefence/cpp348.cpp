#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m, k;
vector<bool>vis;
vector<vector<int>>G;
vector<int>ans;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	vis.resize(n + 1);
	G.resize(n + 1);

	int a, b;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void ustaw(int v, int ile){
    vis[v] = true;

    if(ile == 3) ans.push_back(v);
    ile--;
    if(ile == 0) return;

    for(auto u: G[v])
        ustaw(u, ile);
}

void wypisz(){
	cout << ans.size() << '\n';
	for(auto u: ans)
		cout << u << ' ';
	cout << '\n';
}

int main(){
	wczytaj();
	for(int i = 1; i <= n; i++)
		if(!vis[i]) ustaw(i, 3);

	wypisz();
}