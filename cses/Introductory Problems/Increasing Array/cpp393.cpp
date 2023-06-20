#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, ans = 0, last = 0;

    //get data
    cin >> n;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;

        if(last > x) ans += last - x; // current element must be at least as big as last element
        last = max(last, x);
    }

    cout << ans << '\n';
}

