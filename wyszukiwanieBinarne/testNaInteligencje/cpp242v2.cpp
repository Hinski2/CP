#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

int n, m, q;

map<int, vector<int>>mapa;
vector<int> main_v;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> m;
	main_v.resize(m);
	for(int i = 0; i < m; i++){
		cin >> main_v[i];
		mapa[main_v[i]].push_back(i);
	}

	for(auto u: mapa) //dodanie wartownika 
		mapa[u.first].push_back(inf);

	cin >> q;
}

int wyszukaj(int liczba, int pozycja){
	int l = 0, r = mapa[liczba].size() - 1;

	if(mapa[liczba].size() == 0) return inf;

	while(l < r){
		int mid = (l + r) / 2;

		if(mapa[liczba][mid] < pozycja) l = mid + 1;
		else r = mid;
	}

	return mapa[liczba][(l + r) / 2] + 1;
}

void licz(){
	vector<int> querry_v;
	cin >> n;
	querry_v.resize(n);

	for(int i = 0; i < n; i++)
		cin >> querry_v[i];

	//koniec wyczytywanie, początek liczenia 
	int pos_in_main = 0;
	for(int i = 0; i < n; i++){
		pos_in_main = wyszukaj(querry_v[i], pos_in_main);

		if(pos_in_main >= inf){
			cout << "NIE\n";
			return;
		}
	}

	cout << "TAK\n";
}

int main(){
	wczytaj();
	while(q--)
		licz();
}

