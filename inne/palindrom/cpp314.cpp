#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll n;
ll hsh1, hsh2;
ll power = 197, p = 197;

void wczytaj(){
	char c;
	scanf("%lld", &n);
    scanf("%c", &c);
	
	while(scanf("%c", &c) && c != '\n'){
		hsh1 = ((hsh1 + c) * p) % mod;
		hsh2 = (hsh2 + c * power) % mod;
		power = (power * p) % mod;
	}
}

int main(){
	wczytaj();
	if(hsh1 == hsh2) printf("TAK\n");
	else printf("NIE\n");
}