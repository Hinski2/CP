#include<bits/stdc++.h>
using namespace std;

int n, m;
int c = 1;

vector<int>color, vis, sajz;
vector<vector<int>>G, Gt, Gc;
stack<int>stos;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	color.resize(n + 1);
	G.resize(n + 1);
	vis.resize(n + 1);
	Gt.resize(n + 1);
	sajz.resize(n + 1);

	int a, b;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;

		G[a].push_back(b);
		Gt[b].push_back(a);
	}
}

void dfs1(int v){
       	vis[v] = 1;

	for(auto u: G[v])
		if(vis[u] == 0) dfs1(u);

	stos.push(v);
}

void pokoloruj(int v){
	color[v] = c;

	for(auto u: Gt[v])
		if(!color[u]) pokoloruj(u);
}

void make_c_graph(){
    Gc.resize(c);
	vector<set<int>>vs(c);

	for(int i = 1; i <= n; i++){
		sajz[color[i]]++;

		for(auto u: G[i]){
            if(color[i] == color[u]) continue;

			auto it = vs[color[i]].find(color[u]);
			if(it == vs[color[i]].end()){
				vs[color[i]].insert(color[u]);
				Gc[color[i]].push_back(color[u]);
			}
		}
	}
}

void policz(int v){
	vis[v] = 1;

	for(auto u: Gc[v]){
		if(!vis[u]) policz(u);
		sajz[v] += sajz[u];
	}
}

void wypisz(){
	for(int i = 1; i <= n; i++)
		cout << sajz[color[i]] - 1 << '\n';
}

int main(){
	wczytaj();
	for(int i = 1; i <= n; i++)
		if(vis[i] == 0) dfs1(i);

	while(!stos.empty()){
		int v = stos.top();
		stos.pop();

		if(!color[v]){
			pokoloruj(v);
			c++;
		}
	}

	make_c_graph();
	for(int i = 1; i < c; i++)
		vis[i] = 0;

	for(int i = 1; i < c; i++)
		if(!vis[i]) policz(i);

	wypisz();
}
	
