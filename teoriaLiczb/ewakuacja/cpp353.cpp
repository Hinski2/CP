#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans = 1;
ll n, city_zero, mod, distinct;
vector<vector<int>>G;
vector<ll>liczebnosc_miasta;
vector<ll>liczba_lisci;

vector<ll>silnia;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> city_zero >> mod >> distinct;
	G.resize(n + 1);
	liczebnosc_miasta.resize(n + 1);
	liczba_lisci.resize(n + 1);

	int a, b;
	for(int i = 1; i < n; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for(int i = 1; i <= n; i++)
		cin >> liczebnosc_miasta[i];
}

void compute_silnia(){
	silnia.resize(2 * n + 1);
	silnia[0] = 1;

	for(int i = 1; i <= 2 * n; i++)
		silnia[i] = (silnia[i - 1] * i) % mod;
}

void compute_liczba_lisci(int v, int p = 0){
	for(auto u: G[v]){
		if(u == p) continue;
		compute_liczba_lisci(u, v);

		if(liczba_lisci[u] == 0) liczba_lisci[v]++;
		liczba_lisci[v] += liczba_lisci[u];
	}
}

ll power(ll x, ll k){
	ll res = 1;
	
	while(k){
		if(k & 1){
			res *= x;
			res %= mod;
		}
		x *= x; x %= mod;
		k >>= 1;
	}

	return res;
}

void ewakuacja(int v, int p = -1){
	ll k = liczba_lisci[v];
	ll m = liczebnosc_miasta[v];

	ll res = 0;
	if(distinct){
		res = power(k, m);
	}
	else{
		res = silnia[k + m - 1];
		res *= power(silnia[m], mod - 2); res %= mod;
		res *= power(silnia[k - 1], mod - 2); res %= mod;
	}

	ans *= res; ans %= mod;
	for(auto u: G[v])
		if(u != p && liczba_lisci[u])
			ewakuacja(u, v);
}

int main(){
	//wczytywanie
	wczytaj();

	//pre procesing
	compute_silnia();
	compute_liczba_lisci(city_zero);

	//liczenie
	ewakuacja(city_zero);
	cout << ans << '\n';
}

