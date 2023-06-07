#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll Min = (ll)1e15; 
ll n, ans = 0;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	ll x;
	for(int i = 1; i <= n; i++){
		cin >> x;
		ans = max(ans, x - Min);
		Min = min(Min, x);
	}

	if(ans <= 0) cout << "Nie ma zysku, to ci sie nie oplaca\n";
	else cout << ans << '\n';
}

