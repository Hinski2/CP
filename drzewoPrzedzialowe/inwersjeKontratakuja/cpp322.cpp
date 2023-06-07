#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int base = 1 << 16;
int tree[base << 1];

int n, ans;
vector<int>val;
map<int, int>mapa;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	val.resize(n);

	for(int i = 0; i < n; i++){
		cin >> val[i];
		mapa[val[i]] = 1;
	}
}

void przemapuj(){
	int idx = 0;
	for(auto u: mapa)
		mapa[u.fi] = idx++;

	for(int i = 0; i < n; i++)
		val[i] = mapa[val[i]];
}

void policz(int a, int b){
	a += base; 
	b += base;

	ans += tree[a];
	if(a != b) ans += tree[b];

	while(a >> 1 != b >> 1){
		if(a % 2 == 0) ans += tree[a + 1];
		if(b % 2 == 1) ans += tree[b - 1];

		a >>= 1;
		b >>= 1;
	}
}

void update(int v){
	v += base;

	while(v){
		tree[v]++;
		v >>= 1;
	}
}

int main(){
	wczytaj();
	przemapuj();

	for(auto u: val){
		policz(u + 1, base - 1);
		update(u);
	}

	cout << ans << '\n';
}