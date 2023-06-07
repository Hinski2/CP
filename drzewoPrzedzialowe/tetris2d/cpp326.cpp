#include<bits/stdc++.h>
using namespace std;

const int base = 1 << 20;
int tree[base << 1], lazy[base << 1];

int n, q;
int pz, kz, val;

void pull(int v, int lewy_syn, int prawy_syn){
    if(lazy[v] == 0) return;

	lazy[lewy_syn] = lazy[v];
	lazy[prawy_syn] = lazy[v];

	tree[lewy_syn] = lazy[v];
	tree[prawy_syn] = lazy[v];

	lazy[v] = 0;
}

int query(int v, int l, int r){
	if(kz < l || r < pz)
		return 0;
	else if(pz <= l && r <= kz)
		return tree[v];
	else{
		int lewy_syn = v * 2;
		int prawy_syn = v * 2 + 1;
		int mid = (l + r) / 2;

		pull(v, lewy_syn, prawy_syn);
		return max(query(lewy_syn, l, mid), query(prawy_syn, mid + 1, r));
	}

	return 0;
}

void update(int v, int l, int r){
	if(kz < l || r < pz)
		return;
	else if(pz <= l && r <= kz){
		tree[v] = val;
		lazy[v] = val;
	}
	else{
		int lewy_syn = 2 * v;
		int prawy_syn = 2 * v + 1;
		int mid = (l + r) / 2;

		pull(v, lewy_syn, prawy_syn);
		update(lewy_syn, l, mid);
		update(prawy_syn, mid + 1, r);

		tree[v] = max(tree[lewy_syn], tree[prawy_syn]);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;
    int l, start;
	while(q--){
		cin >> l >> start;

		pz = start;
        kz = start + l - 1;
		val = query(1, 0, base - 1) + 1;
		update(1, 0, base - 1);
	}

	pz = 0;
	kz = n;
	cout << query(1, 0, base - 1) << '\n';
}

