#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll x;
	cin >> x;

	x += (x + 1) / 2;

	cout << x;
}
