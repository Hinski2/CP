#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, m;
bitset<mak>node[mak];

int p[mak], rozmiar[mak];

void wczytanie(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;

		node[a][b] = 1;
		node[b][a] = 1;
	}
}

void ustawienie(){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		node[i][i] = 1;
		rozmiar[i] = 1;
	}
}

int rodzic(int i){
	if(p[i] == i) return i;
	return p[i] = rodzic(p[i]);
}

void join(int a, int b){
	if(rodzic(a) == rodzic(b)) return;
	if(rozmiar[rodzic(a)] < rozmiar[rodzic(b)]) swap(a, b);

	rozmiar[rodzic(a)] += rozmiar[rodzic(b)];
	rozmiar[rodzic(b)] = 0;

	p[b] = rodzic(a);
}

void dsu(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(!node[i][j]) join(i, j);
		}
	}
}

void wypisanie(){
	int licznik = 0;
	for(int i = 1; i <= n; i++) licznik += (rozmiar[i] > 0);

	cout << licznik << "\n";
	for(int i = 1; i <= n; i++) 
		if(rozmiar[i]) 
			cout << rozmiar[i] << " ";
}


int main(){
	wczytanie();
	ustawienie();

	dsu();

	wypisanie();
}
	
