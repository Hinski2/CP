#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n;
ll ans;

vector<ll>val;
vector<int>hi;
vector<bool>ban;
vector<vector<int>>G;

vector<ll>do_dodania[2];
ll ile[2], suma[2], Minus[2];

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	val.resize(n + 1);
	G.resize(n + 1);
    hi.resize(n + 1);
	ban.resize(n + 1);

	int a, b;
	for(int i = 1; i <= n; i++)
		cin >> val[i];
	for(int i = 1; i < n; i++){
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void compute_hi(int v, int p = 0){
	hi[v] = 1;

	for(auto u: G[v]){
        if(u == p || ban[u]) continue;

		compute_hi(u, v);
		hi[v] += hi[u];
	}
}

int find_centroid(int v, int prime, int p){
	int c = v;
	for(auto u: G[v])
		if(!ban[u] && u != p && 2 * hi[u] > hi[prime])
			c = find_centroid(u, prime, v);

	return c;
}

void cross_path(int v, int p, ll last, int c, int h){
	last = (-last + val[v] + mod) % mod;

	do_dodania[h % 2].push_back((last + Minus[h % 2] + mod) % mod);

	if(h % 2 != 1) ans += 2 * last;
	ans += 2 * (last * ile[h % 2] + suma[h % 2]);
	ans = (ans + mod) % mod;

	for(auto u: G[v])
		if(u != p && !ban[u])
			cross_path(u, v, last, c, h + 1);
}

void dodaj(){
	for(auto u: do_dodania[0]){
		suma[0] += u;
		ile[0]++;
	}
    for(auto u: do_dodania[1]){
        suma[1] += u;
        ile[1]++;
    }
    
	do_dodania[0].clear();
    do_dodania[1].clear();
}

void oblicz_przechodzace(int c){
	ile[0] = 0; ile[1] = 0;
    suma[0] = 0; suma[1] = 0;
    Minus[1] = val[c]; Minus[0] = -val[c];

	for(auto u: G[c])
		if(!ban[u]){
			cross_path(u, c, val[c], c, 1);
			dodaj();
		}
    ans = (ans + val[c] + mod) % mod;
}	

void compute_centroid(int v){
	compute_hi(v);
	int c = find_centroid(v, v, v);

	oblicz_przechodzace(c);
	ban[c] = 1;

	for(auto u: G[c])
		if(!ban[u]) compute_centroid(u);
}

int main(){
	wczytaj();
	compute_centroid(1);
	cout << ans << '\n';
}
