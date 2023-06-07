#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a1, a2, b1, b2;

int main(){
	scanf("%lld%lld%lld%lld", &a1, &a2, &b1, &b2);
	if(a1 > b1){
		swap(a1, b1);
		swap(a2, b2);
	}

	//nie nachodzą na siebie
	if(a2 < b1 || b2 < a1)
		printf("NIE\n");

	//całkowicie na siebie nachodzą
	else if(a1 <= b1 && b2 <= a2){
		ll r = b2 - b1;
		printf("%lld\n", r);
	}

	//tylko częściowo nachodzą
	else{
		ll r = a2 - b1;
		printf("%lld\n", r);
	}
}


