#include <bits/stdc++.h>
using namespace std;

int oblicz(){
	int n;
	int odd = 0, even = 0;

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);

		if(x & 1) odd++;	//nieparzysta
		else even++;		//parzysta
	}

	int ans = min(odd, even);
	return ans;
} 

int main(){
	int q;
	scanf("%d", &q);

	while(q--){
		printf("%d\n", oblicz());
	}
}	