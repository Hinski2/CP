//nick na codeforces: Hinski2
//link do profilu: https://codeforces.com/profile/Hinski2
//link do zgłoszenia: https://codeforces.com/contest/1461/submission/186815148

#include<bits/stdc++.h>
using namespace std;

const int mak = 505;

int n, m, ans;
char matrix[mak][mak];
int h[mak][mak];

void wczytaj(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", &matrix[i]);
}

void dp(){
	for(int i = 0; i < m; i++){
		if(matrix[n - 1][i] == '*') h[n - 1][i] = 1;
		else h[n - 1][i] = 0;
	}

	for(int i = n - 2; i >= 0; i--)
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == '*') h[i][j] = h[i + 1][j] + 1;
			else h[i][j] = 0;
		}
}

void sprawdz(int i, int j){
	int l = j, r = j;
	int k = h[i][j];

	while(k){
		if(l < 0 || r >= m || i >= n) return;
		k = min(k, min(h[i][l], h[i][r]));
		if(!k) return;

		i++;
		ans++;
		l--;
		r++;
        k--;
	}
}
		
void policz(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(matrix[i][j] == '*') sprawdz(i, j);
}

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		ans = 0;
		wczytaj();
		dp();
		policz();

		cout << ans << '\n';
	}

}
