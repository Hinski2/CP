#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

ll n, l = 1;

int main(){
	scanf("%lld", &n);

	for(ll i = 2; i * i <= n; i++){
		if(n == 1) break;
		int cnt = 0;		

		while(n % i == 0){
			n /= i;
			cnt++;

			if(cnt == 2){
				cnt = 0;
				l *= i;
			}
		}
		if(cnt) l *= i;
	}

	if(n > 1) l *= n;
	printf("%lld\n", l * l);
}
