#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll process(ll k){
    ll sqr = k * k;
	ll ans = sqr * (sqr - 1LL) / 2LL; //places where I can set 2 knights
	ans -= 4LL * (k - 1) * (k - 2);   //places where 2 knights are fighting
 
	return ans;
}
 
int main(){
	int n;
	cin >> n;
 
	for(ll k = 1; k <= n; k++)
		cout << process(k) << '\n';
}