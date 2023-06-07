#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll base = 1 << 18;
const ll p = 313, mod = 1e9 + 7;

int n, m;
ll tree[base << 1], rTree[base << 1];
vector<ll>power;

void compute_power(){
	power[0] = 1;
	for(int i = 1; i <= n; i++)
		power[i] = (power[i - 1] * p) % mod;
}

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin >> n >> m >> s;
	power.resize(n + 2);
	compute_power();

	s = '#' + s;
	for(int i = 1; i <= n; i++)
		tree[base + i] = (s[i] * power[i]) % mod;
    
    int idx = 1;
	for(int i = n; i > 0; i--)
		rTree[base + i] = (s[i] * power[idx++]) % mod;


	for(int i = base - 1; i > 0; i--){
		tree[i] = (tree[i << 1] + tree[(i << 1) + 1]) % mod;
		rTree[i] = (rTree[i << 1] + rTree[(i << 1) + 1]) % mod;
	}
}

void update(int v, int val){
    int p1 = v;
    int p2 = n - v + 1;
    
	v += base;
	tree[v] = (val * power[p1]) % mod;
	rTree[v] = (val * power[p2]) % mod;

	v >>= 1;
	while(v){
		tree[v] = (tree[v << 1] + tree[(v << 1) + 1]) % mod;
		rTree[v] = (rTree[v << 1] + rTree[(v << 1) + 1]) % mod;

		v >>= 1;
	}
}

bool query(int a, int b){
    ll l = a, r = b;
	ll ans = 0, rAns = 0;

	a += base;
	b += base;
	ans += tree[a];
	rAns += rTree[a];

	if(a != b){
		ans = (ans + tree[b]) % mod;
		rAns = (rAns + rTree[b]) % mod;
	}

	while(a >> 1 != b >> 1){
		if(a % 2 == 0){
			ans = (ans + tree[a + 1]) % mod;
			rAns = (rAns + rTree[a + 1]) % mod;
		}
		if(b % 2 == 1){
			ans = (ans + tree[b - 1]) % mod;
			rAns = (rAns + rTree[b - 1]) % mod;
		}

		a >>= 1;
		b >>= 1;
	}  

    ans = (ans * power[n - r]) % mod;
    rAns = (rAns * power[l - 1]) % mod;

	if(ans == rAns) return true;
	return false;
}

int main(){
	wczytaj();

	int opt;
	while(m--){
		cin >> opt;
		if(opt == 1){
			int v;
            char val;
			cin >> v >> val;

			update(v, (int)val);
		}
		else{
			int a, b;
			cin >> a >> b;

			if(query(a, b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}	
