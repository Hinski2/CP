#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<double>>m;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);

	cin >> n;
	m.resize(n + 1);
	for(int i = 1; i <= n; i++){
		m[i].resize(n + 1);
		cin >> m[i][i];
	}
}

void policz(){
	for(int l = 1; l < n; l++)
        for(int i = 1; i <= n - l; i++)
            for(int k = i; k < i + l; k++)
                m[i][i + l] = max(m[i][i + l], (m[i][k] + m[k + 1][i + l]) / 2);

}

void wypisz(){
	cout << m[1][n] << '\n';
}

int main(){
	wczytaj();
	policz();
	wypisz();
}