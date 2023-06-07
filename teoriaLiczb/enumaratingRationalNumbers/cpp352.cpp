#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mak = 200005;

vector<ll>phi;

void compute_phi(){
	phi.resize(mak);

	for(int i = 0; i < mak; i++)
		phi[i] = i;

	phi[0] = 1;
	for(int i = 2; i < mak; i++)
		if(phi[i] == i)
			for(int j = i; j < mak; j += i)
				phi[j] -= phi[j] / i;
	
	for(int i = 1; i < mak; i++)
		phi[i] += phi[i - 1];	
}

void oblicz(ll x){
	ll lb = lower_bound(phi.begin(), phi.end(), x) - phi.begin();
	ll pos = x - phi[lb - 1];
	ll cnt = 0;

	if(x == 1){
		cout << "0/1\n";
		return;
	}

	for(ll i = 1; i <= lb; i++)
		if(__gcd(i, lb) == 1){
			cnt++;

			if(cnt == pos){
				cout << i << '/' << lb << '\n';
				break;
			}
		}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

	//pre procesing
	compute_phi();

	//odpowiadanie na zapytania

	ll v;
	while(cin >> v && v){
		oblicz(v);
	}
}
