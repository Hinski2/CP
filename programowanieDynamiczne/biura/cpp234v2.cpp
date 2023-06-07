#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, m, ilosc_spujnych;

vector<int>G[mak];
vector<int>miejsce, node_number, rozmiar;

void wczytanie(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;

		a--; b--;

		G[a].push_back(b);
		G[b].push_back(a);
	}

	miejsce.resize(n);
	node_number.resize(n);
	rozmiar.resize(n);
	
	ilosc_spujnych = n;
	for(int i = 0; i < n; i++){
		rozmiar[i] = -1;
		miejsce[i] = i;
	}
}

int find(int v){
	if(rozmiar[v] < 0) return v;
	return rozmiar[v] = find(rozmiar[v]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b) return;
	if(rozmiar[a] > rozmiar[b]) swap(a, b);

	rozmiar[a] += rozmiar[b];
	rozmiar[b] = a;
}

void liczenie(int v){
	for(int i = 0; i < ilosc_spujnych; node_number[miejsce[i++]] = 0);

	for(auto u: G[v]) node_number[find(u)]++;

	for(int i = 0; i < ilosc_spujnych; i++)
		if(node_number[miejsce[i]] != -rozmiar[miejsce[i]]) join(v, miejsce[i]);

	for(int i = 0; i < ilosc_spujnych;){
		if(rozmiar[miejsce[i]] < 0) i++;
		else miejsce[i] = miejsce[--ilosc_spujnych];
	}
}

void wykonczenie(){
	for(int i = 0; i < ilosc_spujnych; i++)
		node_number[i] = -rozmiar[miejsce[i]];

	sort(node_number.begin(), node_number.begin() + ilosc_spujnych);
}

void wypisanie(){
	cout << ilosc_spujnych << "\n";
	for(int i = 0; i < ilosc_spujnych; i++)
		cout << node_number[i] << " ";
}

int main(){
	wczytanie();

	for(int i = 0; i < n; i++){
		liczenie(i);
	}

	wykonczenie();
	wypisanie();
}	


