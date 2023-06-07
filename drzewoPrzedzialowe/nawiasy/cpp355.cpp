#include<bits/stdc++.h>
using namespace std;

const int base = 1 << 15;
const int inf = 1e6 + 7;

int n, q;
vector<int>vec;
vector<int>tree(base << 1, -inf), lazy(base << 1);

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
    vec.resize(n);

	char c;
	for(int i = 0; i < n; i++){
		cin >> c;

		if(c == '(') tree[base + i] = 1;
		else tree[base + i] = -1;

        vec[i] = tree[base + i];
	}
}

void make_tree(){
	for(int i = 1; i < n; i++)
		tree[i + base] += tree[i - 1 + base];

	for(int i = base - 1; i > 0; i--)
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

void push(int v, int l, int r){
	if(lazy[v] == 0) return;

	lazy[l] += lazy[v];
	lazy[r] += lazy[v];
	tree[l] += lazy[v];
	tree[r] += lazy[v];

	lazy[v] = 0;
}

void zmien(int v, int lr, int rr, int lq, int rq, int val){
	if(rr < lq || rq < lr)
		return;
	if(lq <= lr && rr <= rq){
		tree[v] += val;
		lazy[v] += val;
	}
	else{
		int mid = (lr + rr) / 2;
		push(v, v * 2, v * 2 + 1);

		zmien(v * 2, lr, mid, lq, rq, val);
		zmien(v * 2 + 1, mid + 1, rr, lq, rq, val);

		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
} 

int query(int v, int lr, int rr, int lq, int rq){
	if(rr < lq || rq < lr)
		return inf;
	if(lq <= lr && rr <= rq)
		return tree[v];
	else{
		int mid = (lr + rr) / 2;
		push(v, v * 2, v * 2 + 1);
		return min(query(v * 2, lr, mid, lq, rq), query(v * 2 + 1, mid + 1, rr, lq, rq));
	}

	return 0;
}

int main(){
	wczytaj();
	make_tree();
	
	int x;
	cin >> q;
	while(q--){
		cin >> x;

		if(x){
            x--;
			if(vec[x] == 1){
                zmien(1, 0, base - 1, x, n - 1, -2);
                vec[x] = -1;
            }
			else{
                zmien(1, 0, base - 1, x, n - 1, 2);
                vec[x] = 1;
            }
		}
		else{
			if(query(1, 0, base - 1, 0, n - 1) == 0) cout << "TAK\n";
			else cout << "NIE\n";
		}
	}
}
