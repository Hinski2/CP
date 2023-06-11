#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll binpow(ll numb, ll exp){
    ll res = 1;
    while(exp){
        if(exp & 1){
            res *= numb;
            res %= mod;
        }

        numb *= numb;
        numb %= mod;
        exp >>= 1;
    }

    return res;
}


int main(){
    ll n;
    scanf("%lld", &n);
    printf("%lld",binpow(2LL, n));
}
