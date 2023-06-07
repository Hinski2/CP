#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int compute_hi(ll v){
	int hi = 0;
	while(v){
		hi++;
		v >>= 1;
	}

	return hi;
}

int compute_path(ll a, ll b){
	int ans = 0;
	int hiA = compute_hi(a);
	int hiB = compute_hi(b);

	if(hiA < hiB){
		swap(hiA, hiB);
		swap(a, b);
	}

	while(hiA > hiB){
		ans++;
		hiA--;
		a >>= 1;
	}

	if(a == b) return ans;

	while(a >> 1 != b >> 1){
		ans += 2;
		a >>= 1;
		b >>= 1;
	}

	return ans + 2;
}

int main(){
	int q;
	ll a, b;

	scanf("%d", &q);
	while(q--){
		scanf("%lld %lld", &a, &b);
		printf("%d\n", compute_path(a, b));
	}
}
