#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, ans;
map<string, int>mapa; 

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		mapa[s]++;
	}
}

void policz(){
	bool zmiana = 1;
	while(zmiana){
		zmiana = 0;
		for(auto u: mapa){
			ans = max(ans, (int)u.fi.size());
			if(u.se / 2){
				int ile = u.se / 2;

				mapa[u.fi] -= ile * 2;
				mapa[u.fi + u.fi] += ile;
			}
		}
	}
}

void wypisz(){
	cout << ans << '\n';
}

int main(){
	wczytaj();
	policz();
	wypisz();
}
