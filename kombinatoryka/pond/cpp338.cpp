#include <bits/stdc++.h>
using namespace std;

const int mak = 805;

int n, k;
int matrix[mak][mak], suma[mak][mak];

inline void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> matrix[i][j];
}

void compute_suma(int mid){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			suma[i][j] = suma[i - 1][j] + suma[i][j - 1] - suma[i - 1][j - 1] + (matrix[i][j] <= mid);
}

bool zgodnosc_sumy(int i, int j){
	int maksimum = (k * k + 1) / 2;
	i += k - 1;
	j += k - 1;

    int wynik = suma[i][j] - suma[i - k][j] - suma[i][j - k] + suma[i - k][j - k];
	if(wynik >= maksimum) return 1;
	return 0;
}


bool sprawdz(int mid){
	compute_suma(mid);

	for(int i = 1; i <= n - k + 1; i++)
		for(int j = 1; j <= n - k + 1; j++)
			if(zgodnosc_sumy(i, j)) return true;

	return false;
}

int bs(){
	int l = 0, r = 1e9, mid;

	while(l < r){
		mid = (l + r - 1) / 2;

		if(sprawdz(mid)) r = mid;
		else l = mid + 1;
	}

	return l;
}

int main(){
	wczytaj();
	cout << bs() << '\n';
}