#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, apple[25];

ll check(int mask){
    ll a_sum = 0, b_sum = 0;

    for(int i = 0; i < n; i++){
        if(mask & (1 << i)) a_sum += apple[i];
        else b_sum += apple[i];
    }

    return abs(a_sum - b_sum);
}

int main(){
    //get input
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> apple[i];

    //find ans
    ll ans = 25LL * 1e9;
    for(int i = 0; i < (1 << n); i++)
        ans = min(ans, check(i));

    cout << ans << '\n';
}