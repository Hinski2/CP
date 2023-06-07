#include<bits/stdc++.h>	//drzewo przedział punkt
using namespace std;

#define fi first
#define se second

const int base = 1 << 18;
int tree[base << 1];

int n, q;
int idx = 0;
vector<vector<int>>G;
vector<pair<int, int>>range;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	G.resize(n + 1);
	range.resize(n + 1);

	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

int dfs(int v, int ile, int p = -1){
	int lower = idx;
	tree[idx + base] = ile;
	range[v].fi = idx++;

	for(auto u: G[v])
		if(u != p) lower = max(lower, dfs(u, ile + 1, v));

	range[v].se = lower;
	return lower;
}

void zamiana(int l, int r){
	l += base;
	r += base;

	tree[l]--;
	if(l != r) tree[r]--;

	while(l >> 1 != r >> 1){
		if(l % 2 == 0) tree[l + 1]--;
		if(r % 2 == 1) tree[r - 1]--;

		l >>= 1;
		r >>= 1;
	}
}

int querry(int v){
	v += base;

	int ans = 0;
	while(v){
		ans += tree[v];
		v >>= 1;
	}

	return ans;
}

int main(){
	wczytaj();
	dfs(1, 0);

	int q;
	cin >> q;
	q += n - 1;

	while(q--){
		char c;
		cin >> c;

		if(c == 'W'){
			int v;
			cin >> v;
			cout << querry(range[v].fi) << '\n';
		}
		else{
			int a, b;
			cin >> a >> b;
			if(b < a) swap(a, b);

			zamiana(range[b].fi, range[b].se);
		}
	}
}