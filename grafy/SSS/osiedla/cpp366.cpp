#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int mak = 1e6 + 15;
struct road{
	int gdzie;
	int id;
	bool skierowanie;
};

int n, m, c = 1;
int vis[mak];
stack<int>stos;

bool directed[mak], crossed[mak], colour[mak], ans[mak];
vector<vector<road>>G, Gd, Gdt;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	G.resize(n + 1);
	Gd.resize(n + 1);
	Gdt.resize(n + 1);

	int a, b;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		G[a].push_back({b, i, 0});
		G[b].push_back({a, i, 1});
	}
}

void direct(int v){
	directed[v] = true;

	for(auto u: G[v]){
		if(crossed[u.id]) continue;
		crossed[u.id] = true;

		Gd[v].push_back({u.gdzie, u.id, u.skierowanie});
		Gdt[u.gdzie].push_back({v, u.id, u.skierowanie});

		if(!directed[u.gdzie])
			direct(u.gdzie);
	}
}

void make_ans(int v){
	vis[v] = 1;
	for(auto u: Gd[v]){
		ans[u.id] = u.skierowanie;

        if(vis[u.gdzie] != 1) make_ans(u.gdzie);
	}
}

void dfs1(int v){
	vis[v] = 2;

	for(auto u: Gd[v]){
		if(vis[u.gdzie] == 2) continue;
		dfs1(u.gdzie);
	}

	stos.push(v);
}

void dfs2(int v){
	colour[v] = c;

	for(auto u: Gdt[v])
		if(!colour[u.gdzie]) dfs2(u.gdzie);
}

int main(){
	//wczytanie
	wczytaj();

	//liczenie
	for(int i = 1; i <= n; i++)
		if(!directed[i]) direct(i);

    for(int i = 1; i <= n; i++)
        if(vis[i] != 1) make_ans(i);

	//make scc
	for(int i  = 1; i <= n; i++)
        if(vis[i] != 2) dfs1(i);
        
	while(!stos.empty()){
		if(!colour[stos.top()]){
			dfs2(stos.top());
			c++;
		}
		stos.pop();
	}

	//wypisanie
	cout << c - 1 << '\n';
	for(int i = 1; i <= m; i++){
		if(ans[i]) cout << '>';
		else cout << '<';
	}
	cout << '\n';
}
