//nick na codeforces: Hinski2
//link do profilu: https://codeforces.com/profile/Hinski2
//link do zgłoszenia: https://codeforces.com/contest/161/submission/188002502

#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, k;
int ans;

vector<vector<int>>G;
vector<int>hi;
vector<bool>ban;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	ban.resize(n + 1);
	G.resize(n + 1);
	hi.resize(n + 1);

	int a, b;
	for(int i = 1; i < n; i++){
		cin >> a >> b;
		
		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void compute_hi(int v, int p = 0){
	hi[v] = 1;
	for(auto u: G[v])
		if(!ban[u] && u != p){
			compute_hi(u, v);
			hi[v] += hi[u];
		}
}

int find_centroid(int v, int prime, int p){
	int c = v;
	for(auto u: G[v])
		if(!ban[u] && u != p && hi[u] > hi[prime] / 2)
			c = find_centroid(u, prime, v);

	return c;
}

void compute_wysokosc(int v, int h, map<int, int> &toAdd, int p){
	toAdd[h]++;

	for(auto u: G[v])
		if(!ban[u] && u != p)
			compute_wysokosc(u, h + 1, toAdd, v);
}

void polacz_wysokosci(map<int, int> &wysokosc, map<int, int> &toAdd){
	for(auto u: toAdd)
		if(wysokosc.count(k - u.fi))
				ans += wysokosc[k - u.fi] * u.se;
}

void dodaj(map<int, int> &wysokosc, map<int, int> &toAdd){
	for(auto u: toAdd)
		wysokosc[u.fi] += u.se;
}

void oblicz_przechodzace(int c){
	map<int, int>wysokosc;
	wysokosc[0]++;

	for(auto u: G[c])
		if(!ban[u]){
			map<int, int>toAdd;
			compute_wysokosc(u, 1, toAdd, c);
			polacz_wysokosci(wysokosc, toAdd);
			dodaj(wysokosc, toAdd);
		}
}

void compute_centroid(int v, int p = 0){
	compute_hi(v);
	int c = find_centroid(v, v, v);

	oblicz_przechodzace(c);
	ban[c] = true;

	for(auto u: G[c])
		if(!ban[u] && u != p)
			compute_centroid(u, c);
}

int main(){
	wczytaj();
	compute_centroid(1);

	cout << ans << '\n';
}
