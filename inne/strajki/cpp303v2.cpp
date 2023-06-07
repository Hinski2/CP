#include<bits/stdc++.h>
using namespace std;

int n, q, idx = 1;
int liczba_spojnych = 1;
vector<vector<int>>G;
vector<bool>strajk, strajk_kolor;
vector<int>kolor, p, kolejny, wolne_kolor;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	G.resize(n + 1);
	wolne_kolor.resize(n + 1);
	kolor.resize(n + 1);
	p.resize(n + 1);
	strajk.resize(n + 1);
	strajk_kolor.resize(n + 1);
	kolejny.resize(n + 1);

	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void pokoloruj(int v, int c, int parrent){
	p[v] = parrent;
	kolor[v] = c;
	if(G[v].size() > 1 || v == 1) kolejny[v] = ++idx;
	c = idx;

	for(auto u: G[v])
        if(u != parrent)
		    pokoloruj(u, c, v);
}

void wyznacz_skrajne(){
    for(int i = 1; i <= n; i++)
        wolne_kolor[kolor[i]]++;
}

void rozpoczecie(int v){
    strajk[v] = true;
    wolne_kolor[kolor[v]]--;
    liczba_spojnych--;

    if(p[v] && !strajk[p[v]] && !strajk_kolor[kolor[p[v]]]){
        liczba_spojnych++;
    }
    if(kolejny[v]){
        liczba_spojnych += wolne_kolor[kolejny[v]];
    }
}

void zakonczenie(int v){
    strajk[v] = false;
    wolne_kolor[kolor[v]]++;
    liczba_spojnych++;

    if(p[v] && !strajk[p[v]] && !strajk_kolor[kolor[p[v]]]){
        liczba_spojnych--;
    }
    if(kolejny[v]){
        liczba_spojnych -= wolne_kolor[kolejny[v]];
    }
}

int main(){
	wczytaj();
	pokoloruj(1, 1, 0);
	wyznacz_skrajne();

	cin >> q;
	while(q--){
		int v;
		cin >> v;

		if(v > 0) rozpoczecie(v);
		else zakonczenie(-v);

		cout << liczba_spojnych << '\n';
	}
}
