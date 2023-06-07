#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mak = 1e6 + 15;

int n, q;
int droga[mak][2];
ll koszt[mak];

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> droga[i][0] >> droga[i][1];
}

void dfs(int v, ll suma){
	if(droga[v][0]){
		koszt[droga[v][0]] = 2LL * koszt[v];
		dfs(droga[v][0], 2LL * koszt[v]);
	}

	if(droga[v][1]){
		koszt[droga[v][1]] = 2LL * koszt[v] + 1;
		dfs(droga[v][1], 2LL * koszt[v] + 1);
	}
}

int main(){
	wczytaj();
	dfs(1, 0);

	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;

		if(koszt[a] >= koszt[b]) cout << "TAK\n";
		else cout << "NIE\n";
	}
}

