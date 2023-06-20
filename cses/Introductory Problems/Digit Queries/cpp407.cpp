#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int extract(ll numb, ll place){
	for(int i = 0; i < place; i++)
		numb /= 10;
	return numb % 10;
}

int process(ll k){
	ll numb = 9, mod = 1, now = 0;

	while(k - numb * mod > 0){
		k -= numb * mod;
		now += numb;
		mod++;
		numb *= 10;
	}
    
	now += (k + mod - 1) / mod;
	return extract(now, (mod - (k % mod)) % mod);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	while(q--){
		ll k;
		cin >> k;

		cout << process(k) << '\n';
	}
}
