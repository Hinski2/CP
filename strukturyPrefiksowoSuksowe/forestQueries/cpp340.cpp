#include <bits/stdc++.h>
using namespace std;

const int mak = 1005;

int n, m;
int suma[mak][mak];
char forest[mak][mak];

int I1, J1, I2, J2;

void wczytaj(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", &forest[i]);
}

void policz_sumy(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			suma[i][j] = suma[i - 1][j] + suma[i][j - 1] - suma[i - 1][j - 1] + (forest[i][j] == '*' ? 1 : 0);
}

int zapytanie(){
	int ans = suma[I2][J2] - suma[I1 - 1][J2] - suma[I2][J1 - 1] + suma[I1 - 1][J1 - 1];
	return ans;
}

int main(){
	wczytaj();
	policz_sumy();

	while(m--){
		scanf("%d%d%d%d", &I1, &J1, &I2, &J2);
        I1--;
        I2--;
        J1--;
        J2--;
		printf("%d\n", zapytanie());
	}
}

