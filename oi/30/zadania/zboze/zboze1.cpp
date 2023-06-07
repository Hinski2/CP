//jakub iliński, zadanie zboże (brut)
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e18;

int n, k;
ll suma;

vector<int>v;
vector<vector<ll>>matrix;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	matrix.resize(n + 1);
	for(int i = 1; i <= n; i++){
		matrix[i].resize(n + 1);
		for(int j = 1; j <= n; j++)
			matrix[i][j] = inf;
	}

	for(int i = 1; i < n; i++){
		int a, b, s;
		cin >> a >> b >> s;

		matrix[a][b] = s;
		matrix[b][a] = s;
	}
}

void make_matrix(){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(matrix[i][j] > matrix[i][k] + matrix[k][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
}

void zapytanie(){
	int x;
	ll wczesniej = suma;
	cin >> x;

	for(auto u: v)
		suma += matrix[u][x] * 2;
	v.push_back(x);

	cout << suma << ' ' << suma - wczesniej << '\n';
}

int main(){
	wczytaj();
	make_matrix();

	//liczenie
	v.push_back(1);
	while(k--) zapytanie();
}


