//Jakub Iliński zadanie zboże podzadanie 1;
#include <bits/stdc++.h>
using namespace std;

int n, k;
long long ans;

vector<bool> occup;
vector<vector<pair<int, int>>>G;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	occup.resize(n + 1);
	G.resize(n + 1);
	occup[1] = true;

	for(int i = 1; i < n; i++){
		int a, b, s;

		cin >> a >> b >> s;

		G[a].push_back({b, s});
		G[b].push_back({a, s});
	}
}

void policz(int v, int odl, int p = -1){
	if(occup[v]) ans += odl;

	for(auto u: G[v])
		if(u.first != p)
			policz(u.first, odl + u.second, v);
}

int main(){
	wczytaj();

	int v;
	while(k--){
		cin >> v;
		policz(v, 0);
		occup[v] = true;

		cout << ans * 2 << '\n';
	}
}


