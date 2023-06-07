#include <bits/stdc++.h>
using namespace std;

const int mak = 3e5 + 15;

int n;
int dp[mak];

vector<int>G[mak];

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void sprawdzenie(int mid, int v, int p = -1){
    dp[v] = 1;
    for(auto u: G[v])
        if(u != p){
            sprawdzenie(mid, u, v);
            dp[v] += dp[u];
        }
    
    dp[v] = max(1, dp[v] - mid);
}

bool oblicz(int mid){
    sprawdzenie(mid, 1);
    return dp[1] == 1;
}

int bs(){
	int l = 0, r = n;
	while(l < r){
		int mid = (l + r) / 2;
		if(oblicz(mid))
			r = mid;
		else
			l = mid + 1;
	}

	return (l + r) / 2;
}

int main(){
	wczytaj();
	cout << bs() << '\n';
}

