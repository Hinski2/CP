#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, q, idx = 1;
vector<int>start;
vector<pair<int, int>>G, trie;
vector<int>pos, lvl, idx_lvl, t;
vector<bool>vis;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

    G.resize(n + 1);
	pos.resize(n + 1);
    lvl.resize(n + 1);
    idx_lvl.resize(n + 1);
    vis.resize(n + 1);
    trie.resize(n + 1);
    t.resize(n + 1);

	for(int i = 1; i <= n; i++)
		cin >> G[i].fi >> G[i].se; 
}

void wyznacz_start(int v){
	start.push_back(v);
    vis[v] = true;
    if(G[v].fi) wyznacz_start(G[v].fi);
}

void update_trie(int v, int nr){
	t[v] = nr;
	if(G[v].fi && !vis[G[v].fi]){
		if(!trie[t[v]].fi) trie[t[v]].fi = ++idx;
		update_trie(G[v].fi, trie[t[v]].fi);
	}
	if(G[v].se && !vis[G[v].se]){
		if(!trie[t[v]].se) trie[t[v]].se = ++idx;
		update_trie(G[v].se, trie[t[v]].se);
	}
}

void dfs(int v, int h){
	lvl[v] = h;
	pos[v] = idx_lvl[h]++;

	if(trie[v].fi) dfs(trie[v].fi, h + 1);
	if(trie[v].se) dfs(trie[v].se, h + 1);
}

int main(){
	wczytaj();
    wyznacz_start(1);
    for(auto u: start)
    	update_trie(u, 1);
    dfs(1, 0);

    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;

        a = t[a];
        b = t[b];

        if(lvl[a] > lvl[b]) cout << "TAK\n";
        else if(lvl[a] < lvl[b]) cout << "NIE\n";
        else{
            if(pos[a] >= pos[b]) cout << "TAK\n";
            else cout << "NIE\n";
        }
    }
}
