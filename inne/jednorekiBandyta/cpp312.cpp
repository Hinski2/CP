#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, pair<int, int>> ustawienie;

int n;
vector<vector<int>>occ;
map<ustawienie, int>mapa;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	occ.resize(4);

	int x;
	for(int i = 1; i <= 3; i++){
		occ[i].resize(n + 1);

		for(int j = 1; j <= n; j++){
			cin >> x;
			occ[i][x] = j;
		}
	}
}

inline int mod(int a, int b){
    return (a - b + n) % n;
}

void zmapuj(){
	for(int i = 1; i <= n; i++){
        int a = occ[1][i], b = occ[2][i], c = occ[3][i];
        mapa[{mod(a, a), {mod(a, b), mod(a, c)}}]++;
    }
}

int sprawdz(){
	int ans = 0;
	for(auto u: mapa)
		ans = max(ans, u.se);

	return ans;
}

int main(){
	wczytaj();
	zmapuj();
	cout << sprawdz() << '\n';
}