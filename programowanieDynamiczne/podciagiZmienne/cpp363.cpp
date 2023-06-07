#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mak = 5e5 + 15;
const int mod = 1e9 + 7;

ll nie[mak];

inline void oblicz(int &x, ll &last){
    ll wczesniej = last;
	last = last * 2 + 1;
	last = (last - nie[x] + mod) % mod;

	nie[x] += last - wczesniej; nie[x] %= mod;
}

int n;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	ll last = 0;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;

		oblicz(x, last);
	}

	cout << last << '\n';
}
