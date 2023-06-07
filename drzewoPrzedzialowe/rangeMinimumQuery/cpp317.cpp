#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = (ll)1e18;
const int base = 1 << 17;

int n;
vector<ll>tree(base << 1, inf);

ll query(int a, int b){
	ll ans = inf;
	if(a > b) swap(a, b);

	a += base;
	b += base;

	ans = min(tree[a], tree[b]);
	while(a >> 1 != b >> 1){
		if(a % 2 == 0) ans = min(ans, tree[a + 1]);
		if(b % 2 == 1) ans = min(ans, tree[b - 1]);

		a >>= 1;
		b >>= 1;
	}

	return ans;
}	

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	int v;
	for(int i = 0; i < n; i++)
		cin >> tree[base + i];

    for(int i = base - 1; i > 0; i--)
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

int main(){
	wczytaj();

	int q, a, b;
	cin >> q;	
	while(q--){
		cin >> a >> b;
		cout << query(a, b) << '\n';
	}
}
