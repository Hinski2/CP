#include<bits/stdc++.h>
using namespace std;

const int mak = 1005;

int n, m;
int pole[mak][mak];

void wczytaj(){
	cin >> m >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> pole[i][j];
}

void oblicz(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			pole[i][j] += max(pole[i - 1][j], pole[i][j - 1]);
}

int main(){
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--){
		wczytaj();
		oblicz();
		cout << pole[n][m] << '\n';
	}
}
