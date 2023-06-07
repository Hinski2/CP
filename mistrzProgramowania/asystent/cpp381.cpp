#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll n, suma = 1;
vector<ll>val;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	val.resize(n);

	for(int i = 0; i < n; i++){
		cin >> val[i];
		suma *= val[i]; suma %= mod;
	}
}

ll qp(ll x, ll k){
	ll res = 1;
	while(k){
		if(k & 1) res = (res * x) % mod;
		x = (x * x) % mod;
		k >>= 1;
	}

	return res;
}	

void policz(){
	for(auto u: val){
		ll ans = suma * qp(u, mod - 2); ans %= mod;
		cout << ans << ' ';
	}
	
	cout << '\n';
}

int main(){
	wczytaj();
	policz();
}