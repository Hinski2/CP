#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n;
ll ans;

vector<ll>val;
vector<vector<int>>G;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	val.resize(n + 1);
	G.resize(n + 1);

	int a, b;
	for(int i = 1; i <= n; i++)
		cin >> val[i];
	for(int i = 1; i < n; i++){
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void policz(int v, int p, ll mlt, ll sum){
        sum += val[v] * mlt + mod; sum %= mod;
		ans += sum + mod; ans %= mod;
		mlt *= -1;

		for(auto u: G[v])
			if(u != p) policz(u, v, mlt, sum);
}

int main(){
	wczytaj();
	for(int i = 1; i <= n; i++){
		policz(i, i, 1, 0);
	}

	cout << ans << '\n';
}
