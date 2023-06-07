#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second 

int n;
vector<pair<double, int>>czynnosc;


void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	czynnosc.resize(n);

	for(int i = 0; i < n; i++){
		double a, b;
		cin >> a >> b;

		czynnosc[i].fi = b / a;
		czynnosc[i].se = i;
	}
}

void wypisz(){
	for(auto u: czynnosc)
		cout << u.se + 1 << '\n';
}

int main(){
	wczytaj();
	sort(czynnosc.begin(), czynnosc.end());
	wypisz();
}