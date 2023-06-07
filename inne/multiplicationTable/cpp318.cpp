#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;

int main(){
	scanf("%lld", &n);

	ll l = 0, r = n * n, mid, low;
	while(l < r){
		low = 0;
		mid = (l + r) / 2;

		for(int i = 1; i <= n; i++)
			low += min(n, mid / i);

		if(low >= (n * n + 1) / 2) r = mid;
		else l = mid + 1;
	}

	printf("%lld\n", r);
}
		
