#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, maks, suma;
vector<ll>power;

inline void wczytaj(){
	scanf("%lld", &n);
}

inline void wyznacz(){
	ll p = 1, m = n;
	power.push_back(p);

	while(p < m){
        suma += p;
        m -= p;
		p <<= 1;
		power.push_back(p);
	}

    power.pop_back();
	maks = p;
}

int policz(){
    int p = power.size() - 1, ans = 0;
    suma -= power[p];

	while(n){
		while(power[p] > n - suma && p)
            suma -= power[--p];
		n -= power[p];
		ans++;
	}

	return ans;
}

int main(){
	wczytaj();
	wyznacz();
	printf("%d\n", policz());
}