#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int>g, in;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	g.resize(n + 1);
	in.resize(n + 1);

	for(int i = 1; i <= n; i++){
		cin >> g[i];
		in[g[i]]++;
	}
}

void dfs(int v){
	in[v] = -1;
	if(in[g[v]] != -1) dfs(g[v]);
}

void usun_zbedne(){
	queue<int>kolejka;

	for(int i = 1; i <= n; i++)
		if(in[i] == 0) kolejka.push(i);

	while(!kolejka.empty()){
		int v = kolejka.front();
		kolejka.pop();

		in[v] = -1;
		in[g[v]]--;

		if(in[g[v]] == 0) kolejka.push(g[v]);
	}
}

void policz(){
	for(int i = 1; i <= n; i++)
		if(in[i] != -1){
		 	dfs(i);
		 	ans++;
		 }
}

int main(){
	wczytaj();
	usun_zbedne();
	policz();

	cout << ans << '\n';
}