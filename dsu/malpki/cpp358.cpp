#include<bits/stdc++.h>
using namespace std;

const int mak = 2e5 + 10;
const int nie = -2;

int n, q;
int reka[mak][2], ans[mak];
int rozlaczenie[2 * mak][2];

vector<int>G[mak];

void wczytaj(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   	cin >> n >> q;

   	for(int i = 0; i < n; i++)
   		for(int j: {0, 1}){
   			cin >> reka[i][j];
   			if(reka[i][j] != -1) reka[i][j]--;
   		}

   	int a, b;
   	for(int i = 0; i < q; i++){
   		cin >> a >> b;
   		a--; b--;

   		rozlaczenie[i][0] = reka[a][b];
   		rozlaczenie[i][1] = a;
   		reka[a][b] = -1;
   	}
}

void ustaw(){
	for(int i = 0; i < n; i++)
		ans[i] = -2;

	for(int i = 0; i < n; i++)
		for(int j: {0, 1})
			if(reka[i][j] != -1){
				G[reka[i][j]].push_back(i);
				G[i].push_back(reka[i][j]);
			}
}

void dfs(int v, int tajm){
	if(ans[v] != -2) return;

	ans[v] = tajm;
	for(auto u: G[v])
		dfs(u, tajm);
}

void policz(){
	dfs(0, -1);

	for(int i = q - 1; i >= 0; i--){
		int a = rozlaczenie[i][0];
		int b = rozlaczenie[i][1];

		if(ans[a] != -2 && ans[b] == -2) dfs(b, i);
		if(ans[b] != -2 && ans[a] == -2) dfs(a, i);

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void wypisz(){
	for(int i = 0; i < n; i++)
		cout << ans[i] << '\n';
}

int main(){
	wczytaj();
	ustaw();
	policz();
	wypisz();
}
	
