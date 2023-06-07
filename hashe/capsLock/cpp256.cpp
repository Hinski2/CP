#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;
const int mod = 1e9 + 7;
const int p = 179;

int power[mak];
int pref[mak], hsh_b;

vector<int>zamien;
string a, b;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
    zamien.resize((int)a.size());
}

void wyznacz_potegi(){
	power[0] = 1;
	for(int i = 1; i < mak; i++)
		power[i] = (1LL * power[i - 1] * p) % mod;
}

void zahaszuj_a(){
	pref[0] = 0;

	for(int i = 1; i <= a.size(); i++)
		pref[i] = (1LL * pref[i - 1] * p + a[i - 1]) % mod;
}

void zahaszuj_b(){
	hsh_b = b[0];
	for(int i = 1; i < b.size(); i++)
		hsh_b = (1LL * hsh_b * p + b[i]) % mod;
}

void sprawdzenie(int hsh_a, int start){
	if(hsh_a != hsh_b) return;
	zamien[start] += 1; 
    zamien[start + b.size()] -= 1;
}

void liczenie(){
	for(int i = b.size(); i <= a.size(); i++){
		int hsh_a = 1LL * (pref[i] - ((1LL * pref[i - b.size()] * power[b.size()]) % mod) + mod) % mod;
		sprawdzenie(hsh_a, i - b.size());
	}
}

void wypisanie(){
    if(zamien[0] > 0) a[0] -= 32;
    for(int i = 1; i < a.size(); i++){
        zamien[i] += zamien[i - 1];
        if(zamien[i] > 0) a[i] -= 32;
    }

    for(auto u: a)
        cout << u;
    cout << "\n";
}

int main(){
	wczytaj();
	wyznacz_potegi();
	zahaszuj_a();
	zahaszuj_b();
	liczenie();
	wypisanie();
}