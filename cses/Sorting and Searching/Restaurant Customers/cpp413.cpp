#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define Start 1
#define End 0

int n, ans;
vector<pair<int, int>> cust;

bool cmp(pair<int, int>a, pair<int, int>b){
	if(a.fi != b.fi) return a.fi < b.fi;
	return a.se == Start;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		int a, b;
		cin >> a >> b;
		cust.push_back({a, Start});
		cust.push_back({b, End});
	}

	sort(cust.begin(), cust.end(), cmp);

	int now = 0;
	for(auto u: cust){
		if(u.se == Start) ans = max(ans, ++now);
		else now--;
	}

	cout << ans << '\n';
}
		

