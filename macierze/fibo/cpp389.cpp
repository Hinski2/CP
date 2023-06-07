#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

void mult(vector<vector<ll>> &a, vector<vector<ll>> b){
    vector<vector<ll>>m(2, vector<ll>(2));

	for(int k = 0; k < 2; k++)
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				m[i][j] += (a[i][k] * b[k][j]) % mod;

    a = m;
}			


ll fib(int q){
	vector<vector<ll>> res(2, vector<ll>(2)), matrix(2, vector<ll>(2));

	res[0][0] = res[1][1] = 1;
	matrix[0][0] = matrix[0][1] = matrix[1][0] = 1;

	while(q){
		if(q & 1) mult(res, matrix);
		mult(matrix, matrix);
		
		q >>= 1;
	}

	return res[1][0];
} 

int main(){
	int q;
	cin >> q;

	cout << fib(q) << '\n';
}