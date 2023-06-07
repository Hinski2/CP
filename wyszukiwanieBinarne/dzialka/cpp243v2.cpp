#include <bits/stdc++.h>
using namespace std;

const int mak = 2005;

int n;
int pole[mak][mak];
pair<int, int> odl[mak][mak];

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			bool x;
			cin >> x;

			if(x) pole[i][j] = 0;
			else pole[i][j] = 1;
		}
}

void zparuj(){
	int ans = 0;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			if(pole[i][j] == 0) odl[i][j] = {0, 0};
			else{
				int x = min(odl[i - 1][j].first, odl[i][j - 1].first) + 1;
				int y = min(odl[i - 1][j].second, odl[i][j - 1].second) + 1;
				odl[i][j] = {x, y};

				ans = max(ans, x * y);
			}
		}

	cout << ans << "\n";
}

int main(){
	wczytaj();
	zparuj();
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= n; j++)
	// 		cout << "{" << odl[i][j].first << " " << odl[i][j].second << "} ";
	// 	cout << "\n";
	// }
}
