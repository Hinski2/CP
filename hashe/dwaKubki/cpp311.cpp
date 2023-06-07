#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll p = 197;
const ll mod = 1e9 + 7;

ll n, hasz;
vector<ll>hsh, power;
vector<ll>s1, s2;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	s1.resize(n + 1);
	s2.resize(n + 1);
	hsh.resize(2 * n + 1);
	power.resize(2 * n + 1);

	for(int i = 1; i <= n; i++)
		cin >> s1[i];

	for(int i = 1; i <= n; i++)
		cin >> s2[i];

	for(int i = 1; i <= n; i++)
		s2.push_back(s2[i]);
}

void compute_power(){
	power[0] = 1;

	for(int i = 1; i <= 2 * n; i++)
		power[i] = (power[i - 1] * p) % mod;
}

void compute_hasz(){
	for(int i = 1; i <= n; i++)
		hasz = (hasz * p + s1[i]) % mod;
}

void compute_hsh(){
	for(int i = 1; i <= 2 * n; i++)
		hsh[i] = (hsh[i - 1] * p + s2[i]) % mod;
}

bool sprawdz(int pocz, int kon){
	ll hasz2 = (hsh[pocz] - ((hsh[kon] * power[n]) % mod) + mod) % mod;

	if(hasz == hasz2) return true;
	return false;
}

bool przekrecony(){
	for(int i = n; i <= 2 * n; i++)
		if(sprawdz(i, i - n)) return true;

	return false;
}

int main(){
	//wczytanie
	wczytaj();

	//preprocesing
	compute_power();
	compute_hasz();
	compute_hsh();

	//liczenie
	if(przekrecony()) cout << "TAK\n";
	else cout << "NIE\n";
}

