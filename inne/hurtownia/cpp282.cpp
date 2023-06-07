#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, bilans;

int ans;
vector<int>wynik;
vector<int>dostaje, cena;
priority_queue<pair<ll, int>>kolejka;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	dostaje.resize(n + 1);
	cena.resize(n + 1);

	for(int i = 1; i <= n; i++)
		cin >> dostaje[i];
	for(int i = 1; i <= n; i++)
		cin >> cena[i];
}

void policz(){
	for(int i = 1; i <= n; i++){
		bilans += dostaje[i];

		if(cena[i] <= bilans){
			ans++;
			kolejka.push({cena[i], i});
			bilans -= cena[i];
		}
		else if(!kolejka.empty() && cena[i] < kolejka.top().first){
			bilans += kolejka.top().first - cena[i];
			kolejka.pop();
			kolejka.push({cena[i], i});
		}
	}
}

void wypisz(){
	cout << ans << '\n';
	while(!kolejka.empty()){
		wynik.push_back(kolejka.top().second);
		kolejka.pop();
	}

	sort(wynik.begin(), wynik.end());
	for(auto u: wynik)
		cout << u << '\n';
}

int main(){
	wczytaj();
	policz();
	wypisz();
}

