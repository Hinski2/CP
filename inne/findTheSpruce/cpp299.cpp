#include<bits/stdc++.h>
using namespace std;

const int mak = 505;

int n, m, ans;
char matrix[mak][mak];

void wczytaj(){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf("%s", &matrix[i]);
}

void sprawdz(int i, int j){
	int l = j, r = j;
	ans++;

	while(true){
		i++;
		l--;
		r++;

		if(l < 0 || r >= m || i >= n) return;
		for(int k = l; k <= r; k++)
			if(matrix[i][k] != '*') return;
		ans++;
	}
}

void policz(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == '*') sprawdz(i, j);
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ans = 0;
		wczytaj();
		policz();
		printf("%d\n", ans);
	}
}


