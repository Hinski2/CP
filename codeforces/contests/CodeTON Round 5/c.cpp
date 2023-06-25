#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void solve(){
	//get n
	int n;
	cin >> n;

	//get values
 	vector<int> values(n + 1), dp(n + 1, -inf), not_inc(n + 1, -inf);
 	for(int i = 1; i <= n; i++) cin >> values[i];

 	//make dp
 	dp[0] = 0;
 	for(int i = 1, prev = 0; i <= n; i++){
 		dp[i] = max(prev, i + not_inc[values[i]]);
 		not_inc[values[i]] = max(not_inc[values[i]], dp[i - 1] - i + 1);
 		prev = max(prev, dp[i]);
 	}

 	cout << dp[n] << '\n';
 }

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	while(q--){
		solve();
	}
}

