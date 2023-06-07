#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
const ll inv = 499122177;

int n, m;
inline void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
}

ll compute_suma(ll fir, ll r, ll l){ //r - różnica ciągu arytmetyczenego, l - liczba liczb
	ll las = fir + (l - 1) * r; las %= mod;
	ll res = fir + las; res %= mod;

	res *= l; res %= mod;
	res *= inv; res %= mod;

	return res;
}

pll compute_row(ll i, ll j1, ll j2){
	if((i + j1) % 2) j1++;
	if((i + j2) % 2) j2--;
	if(j1 > j2) return {0, 0};

	ll fir = (i - 1) * m + j1; fir %= mod;
	ll l = 1 + (j2 - j1) / 2;
	ll suma = compute_suma(fir, 2, l);

	l *= 2; l %= mod;
	l *= m; l %= mod;

	return {suma, l};
}

ll oblicz(ll i1, ll i2, ll j1, ll j2){
	pll row1 = compute_row(i1, j1, j2);
	pll row2 = compute_row(i1 + 1, j1, j2);
	ll col1 = (i2 - i1 + 1) / 2 + (i2 - i1 + 1) % 2;
	ll col2 = (i2 - i1 + 1) / 2;

	ll res = compute_suma(row1.fi, row1.se, col1); res %= mod;
	res += compute_suma(row2.fi, row2.se, col2); res %= mod;

	return res; 
}

int main(){
	//wczytanie
	wczytaj();

	//odpowiadanie na zapytania
	int q;
	cin >> q;

	ll i1, i2, j1, j2;
	while(q--){
		cin >> i1 >> i2 >> j1 >> j2;
		cout << oblicz(i1, i2, j1, j2) << '\n';
	}
}





