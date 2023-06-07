#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int p = 197;

int licznik;
ll hshB;

vector<ll> power;
vector<ll> hshA;

string a, b;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
}

void powerowanie(){
	power.push_back(1);
	int d = max((int)a.size(), (int)b.size());
	for(int i = 1; i < d; i++){
		ll x = (power[i - 1] * p) % mod;
		power.push_back(x);
	}
}

void zahaszuj_a(){
	hshA.push_back(0);
	for(int i = 1; i <= (int)a.size(); i++){
		ll x = hshA[i - 1] * p + a[i - 1];
		hshA.push_back(x % mod);
	}
}

void zahaszuj_b(){
	for(int i = 0; i < (int)b.size(); i++)
		hshB = (hshB * p + b[i]) % mod;
}

int policz(){
	for(int i = (int)b.size(); i <= (int)a.size(); i++){
		ll hsh = (hshA[i] - ((hshA[i - b.size()] * power[b.size()]) % mod) + mod) % mod;
		if(hsh == hshB) licznik++;
	}

	return licznik;
} 

int main(){
	wczytaj();
	powerowanie();
	zahaszuj_a();
	zahaszuj_b();
	cout << policz() << "\n";
}