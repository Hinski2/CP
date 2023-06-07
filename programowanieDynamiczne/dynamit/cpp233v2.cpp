#include <bits/stdc++.h>
using namespace std;

const int mak = 3e5 + 15;
const int inf = 1e9 + 7;

int n, m;
int uzyte_dynamity;

bool dynamit[mak];

vector<int>G[mak];
vector<int>zdetonowany(mak, inf);
vector<int>nie_zdetonowany(mak, -inf);

void dfs(int v, int odl, int p = -1){
	if(dynamit[v]) nie_zdetonowany[v] = 0;

	for(auto u: G[v]){
		if(u == p)continue;
		dfs(u, odl, v);

		nie_zdetonowany[v] = max(nie_zdetonowany[v], nie_zdetonowany[u] + 1);
		zdetonowany[v] = min(zdetonowany[v], zdetonowany[u] + 1);
	}

	if(zdetonowany[v] + nie_zdetonowany[v] <= odl) nie_zdetonowany[v] = -inf;
	if(nie_zdetonowany[v] == odl || (v == 1 && nie_zdetonowany[v] != inf)){
		uzyte_dynamity++;
		nie_zdetonowany[v] = -inf;
		zdetonowany[v] = 0;
	}
}

bool sprawdzenie(int odl){
	uzyte_dynamity = 0;

	dfs(1, odl);

	if(uzyte_dynamity <= m) return true;
	return false;
}


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

int liczenie(){
	int l = 0, r = mak, mid;
	while(l < r){
		mid = (l + r) / 2;

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
