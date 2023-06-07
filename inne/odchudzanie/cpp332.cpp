#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;
int n, maks = -inf;
int ans;

int main(){
	scanf("%d", &n);

	int v;
	while(n--){
		scanf("%d", &v);
		maks = max(maks, v);
		ans = max(ans, maks - v);
	}

	printf("%d\n", ans);
}

