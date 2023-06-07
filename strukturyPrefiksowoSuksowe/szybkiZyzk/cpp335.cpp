#include<bits/stdc++.h>
using namespace std;

const int mak = 1e3 + 5;

int n, m;
int liczba[mak][mak], minusy[mak][mak], zera[mak][mak];

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int x;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> liczba[i][j];
}

void compute_minusy(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			minusy[i][j] = minusy[i - 1][j] + minusy[i][j - 1] - minusy[i - 1][j - 1] + ((liczba[i][j] < 0) ? 1 : 0); 
}

void compute_zera(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			zera[i][j] = zera[i - 1][j] + zera[i][j - 1] - zera[i - 1][j - 1] + ((liczba[i][j] == 0) ? 1 : 0); 
}

void zapytanie(int i1, int j1, int i2, int j2){
	int suma_minusy = minusy[i2][j2] - minusy[i2][j1 - 1] - minusy[i1 - 1][j2] + minusy[i1 - 1][j1 - 1];
	int suma_zera = zera[i2][j2] - zera[i2][j1 - 1] - zera[i1 - 1][j2] + zera[i1 - 1][j1 - 1];

	if(suma_zera > 0) cout << "0\n";
	else if(suma_minusy % 2 == 0) cout << "1\n";
	else cout << "-1\n";
}

int main(){
	//wczytanie
	wczytaj();

	//preprocesing
	compute_minusy();
	compute_zera();

	//obsługa zapytań
	int q;
	cin >> q;

	int i1, i2, j1, j2;
	while(q--){
		cin >> i1 >> j1 >> i2 >> j2;
		zapytanie(i1, j1, i2, j2);
	}
}


