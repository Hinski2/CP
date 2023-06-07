#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, ans;
vector<int>zwrot;
vector<int>pref_jedynek, suf_zer;

void wczytaj(){
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	cin >> n;
	zwrot.resize(n + 1);
	pref_jedynek.resize(n + 1);
	suf_zer.resize(n + 1);

	for(int i = 1; i <= n; i++)
		cin >> zwrot[i];
}

void compute_pref(){
	pref_jedynek[0] = 0;

	for(int i = 1; i <= n; i++)
		pref_jedynek[i] = pref_jedynek[i - 1] + zwrot[i];
}

void compute_suf(){
	suf_zer[n] = !zwrot[n];

	for(int i = n - 1; i > 0; i--)
		suf_zer[i] = suf_zer[i + 1] + (!zwrot[i]);
}

void wyznacz(){
	ans = 1e6 + 7;
	for(int i = 0; i < n; i++)
		ans = min(ans, n - (pref_jedynek[i] + suf_zer[i + 1]));

	ans = min(ans, n - pref_jedynek[n]);
}

int main(){
	//wczytanie
	wczytaj();

	//preprocesing
	compute_pref();
	compute_suf();

	//liczenie
	wyznacz();

	//wypisanie
	cout << ans << '\n';
}

