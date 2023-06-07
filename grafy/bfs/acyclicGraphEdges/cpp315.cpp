#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>>G;
vector<pair<int, int>>ans;
vector<bool> vis;
queue<int>kolejka;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	G.resize(n + 1);
	vis.resize(n + 1);

	int a, b;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void policz(){
	while(!kolejka.empty()){
		int v = kolejka.front();
		kolejka.pop();

		if(!vis[v]){
			vis[v] = true;
			for(auto u: G[v])
				if(!vis[u]){
					kolejka.push(u);
					ans.push_back({v, u});
				}
		}
	}
}	

void wypisz(){
	for(auto u: ans)
		cout << u.first << ' ' << u.second << '\n';
}

int main(){
	wczytaj();
	for(int i = 1; i <= n; i++)
		if(!vis[i]){
			kolejka.push(i);
			policz();
		}
	wypisz();
}
