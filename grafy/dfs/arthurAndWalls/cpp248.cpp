#include <bits/stdc++.h>
using namespace std;

const int mak = 2015;

pair<int, int> vektor[]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n, m;
bool pole[mak][mak], odwiedzony[mak][mak], ans[mak][mak];

int gora, dol, lewo, prawo;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			char c;
			cin >> c;

			if(c == '.') pole[i][j] = 1;
		}
}

void dfs(int i, int j){
	odwiedzony[i][j] = true;
	if(gora > i) gora = i;
	else if(dol < i) dol = i;

	if(lewo > j) lewo = j;
	else if(prawo < j) prawo = j;

	for(int k = 0; k < 4; k++){
		int x = i + vektor[k].first;
		int y = j + vektor[k].second;

		if(!odwiedzony[x][y] && pole[x][y] && (x > 0 && x <= n) && (y > 0 && y <= m))
			dfs(x, y);
	}
}

void ustaw(){
	for(int i = gora; i <= dol; i++)
		for(int j = lewo; j <= prawo; j++)
			ans[i][j] = 1;
}

void policz(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(!odwiedzony[i][j] && pole[i][j]){
				gora = i;
				dol = i;
				lewo = j;
				prawo = j;

				dfs(i, j);
				ustaw();
			}
}

void wypisz(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(ans[i][j] || pole[i][j]) cout << ".";
			else cout << "*";
		}
		cout << "\n";
	}
}

int main(){
	wczytaj();
	policz();
	wypisz();
}
