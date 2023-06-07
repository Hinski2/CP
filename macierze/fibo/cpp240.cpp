#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int n = 2;

void ustawnienie(vector<vector<ll>> &jeden_matrix, vector<vector<ll>> &ans_matrix){
 	jeden_matrix.resize(n);
 	ans_matrix.resize(n);

 	for(int i = 0; i < n; i++){
 		jeden_matrix[i].resize(n);
 		ans_matrix[i].resize(n);
 	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			ans_matrix[i][j] = (i == j);

	jeden_matrix[0][0] = 1;
	jeden_matrix[0][1] = 1;
	jeden_matrix[1][0] = 1;
	jeden_matrix[1][1] = 0;
}

void multiply(vector<vector<ll>> &a_matrix, vector<vector<ll>> b_matrix){
    vector<vector<ll>>pomocniczy_matrix(n, vector<ll>(n, 0));

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++){
				pomocniczy_matrix[i][j] += a_matrix[i][k] * b_matrix[k][j];
                pomocniczy_matrix[i][j] = pomocniczy_matrix[i][j] % mod;
            }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a_matrix[i][j] = pomocniczy_matrix[i][j];
}

void wypisz(vector<vector<ll>> ans_matrix){
	cout << ans_matrix[0][0] << "\n";
}

void fib(ll w){
	vector<vector<ll>> jeden_matrix, ans_matrix;
	ustawnienie(jeden_matrix, ans_matrix);

	while(w){
		if(w & 1) multiply(ans_matrix, jeden_matrix);
		multiply(jeden_matrix, jeden_matrix);

		w /= 2;
	}

	wypisz(ans_matrix);
}


int main(){
	ll w;
	scanf("%lld", &w);

	fib(w - 1);
}