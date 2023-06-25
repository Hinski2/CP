#include <bits/stdc++.h>
using namespace std;

long long policz(){
	long long ans = 0;
	int n, x;
	map<int, int>mapa;

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		mapa[x - i]++;
	}

	for(auto u: mapa)
		ans += 1LL * u.second * (u.second - 1) / 2;

	return ans;
}

int main(){
	int q;
	scanf("%d", &q);

	while(q--){
		printf("%lld\n", policz());
	}
}