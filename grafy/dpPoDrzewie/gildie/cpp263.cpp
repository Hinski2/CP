#include <bits/stdc++.h>
using namespace std;

const int mak = 2e5 + 15;

int n, m;
int ans[mak];
bool odwiedzony[mak];

vector<int>G[mak];

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

bool sprawdz_konec(){
	bool koniec = false;

	for(int i = 1; i <= n; i++)
		if((int)G[i].size() == 0) koniec = true;

	return koniec;
}

void dfs(int v, int opt){
	ans[v] = opt;
    odwiedzony[v] = true;

	if(opt == 1) opt = 2;
	else opt = 1;

	for(auto u: G[v])
		if(!odwiedzony[u])
			dfs(u, opt);
}

void policz(){
	for(int i = 1; i <= n; i++)
		if(!odwiedzony[i]) dfs(i, 1);
}

void wypisz(){
	cout << "TAK\n";
	for(int i = 1; i <= n; i++){
		if(ans[i] == 1) cout << "K\n";
		else cout << "S\n";
	}
}

int main(){
	wczytaj();
	if(sprawdz_konec() == true){
		cout << "NIE\n";
		return 0;
	}
	policz();
	wypisz();
}
