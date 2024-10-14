#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n; cin >> n;
    ll a = 0, b = 1, c;

    if(n == 0) cout << a << '\n';
    else if(n == 1) cout << b << '\n';

    for(ll i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;

        if(i == n) cout << c << '\n';
    }
}
