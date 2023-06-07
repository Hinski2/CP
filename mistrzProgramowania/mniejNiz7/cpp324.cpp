#include <bits/stdc++.h>
using namespace std;

int q, ans;
int main(){
	scanf("%d", &q);

	int v;
	while(q--){
		scanf("%d", &v);
		if(v < 7) ans++;
	}

	printf("%d\n", ans);
}