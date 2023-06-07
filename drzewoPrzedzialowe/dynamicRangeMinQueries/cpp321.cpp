#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 18;

int n, q;
int tree[base << 1];

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> tree[base + i];

	for(int i = base - 1; i > 0; i--)
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

void update(int v, int val){
	v += base;
	tree[v] = val;
	v >>= 1;

	while(v){
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
		v >>= 1;
	}
}

int query(int a, int b){
	a += base;
	b += base;

	int ans = min(tree[a], tree[b]);
	while(a >> 1 != b >> 1){
		if(a % 2 == 0) ans = min(ans, tree[a + 1]);
		if(b % 2 == 1) ans = min(ans, tree[b - 1]);

		a >>= 1;
		b >>= 1;
	}

	return ans;
}

int main(){
	wczytaj();

	int typ;
	while(q--){
		cin >> typ;

		if(typ == 1){
			int v, val;
			cin >> v >> val;

			update(v, val);
		}
		else{
			int a, b;
			cin >> a >> b;
			cout << query(a, b) << '\n';
		}
	}
}
