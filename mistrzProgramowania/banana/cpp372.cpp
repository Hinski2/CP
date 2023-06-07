#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 26;

void policz(){
	ll x;
	stack<int>stos;

	cin >> x;
	while(x){
		x--;
		stos.push(x % mod);
		x /= mod;
	}

	while(!stos.empty()){
		int v = stos.top();
		stos.pop();

		v += 'A';
		cout << (char)v;
	}

	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	while(q--){
		policz();
	}
}
