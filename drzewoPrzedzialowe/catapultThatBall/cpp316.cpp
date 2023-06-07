#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 16;

int n, q;
int tree[base << 1];

void update(int v, int val){
	v += base;

	tree[v] = val;
	v >>= 1;

	while(v){
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
		v >>= 1;
	}
}

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;

	int hi;
	for(int i = 1; i <= n; i++){
		cin >> hi;
		update(i, hi);
	}
}

int querry(int a, int b){
	int ans = 0;

	a += base;
	b += base;

	ans = max(tree[a], tree[b]);
	while(a >> 1 != b >> 1){
		if(a % 2 == 0) ans = max(ans, tree[a + 1]);
		if(b % 2 == 1) ans = max(ans, tree[b - 1]);

		a >>= 1;
		b >>= 1;
	}

	return ans;
}

int main(){
	wczytaj();
	
	int a, b, ans = 0;
	while(q--){
		cin >> a >> b;

		if(tree[a + base] >= querry(a, b - 1)) ans++;
	}

	cout << ans << '\n';
}
