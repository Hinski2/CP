//Jakub Iliński zadanie zboże, podzadanie 2;
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int base = 1 << 17;

ll up[base << 1], down[base << 1];

int n, k;
ll ans;

vector<pair<int, int>>Gu, Gd;
vector<ll>pref, suf;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	Gu.resize(n + 1);
	Gd.resize(n + 1);
	pref.resize(n + 1);
	suf.resize(n + 1);

	for(int i = 1; i <= n; i++){
		int a, b, s;
		cin >> a >> b >> s;

		if(a < b) swap(a, b);

		Gd[a] = {b, s};
		Gu[b] = {a, s};
	}
}

void wyznacz_odl(){
	for(int i = 2; i <= n; i++)
		pref[i] = pref[i - 1] + Gd[i - 1].second;

	for(int i = n - 1; i >= 1; i--)
		suf[i] = suf[i + 1] + Gu[i + 1].second;
}

int main(){
	wczytaj();
	wyznacz_odl();
	for(int i = 1; i <= k; i++){
		int v;
		cin >> v;

			

}