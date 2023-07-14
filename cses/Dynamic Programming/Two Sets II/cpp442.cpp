#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tree<int,null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;
//erase: oms.erase(oms.upper_bound(value))

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 62625 + 7;

int n, target;
ll dp[mak];

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    target = n * (n + 1);
    if(target % 4 != 0){
        cout << "0\n";
        exit(0);
    }

    target /= 4;
}

ll binpow(ll numb, ll pow){
   ll res = 1;
   while(pow){
    if(pow & 1) res = (res * numb) % mod;
    numb = (numb * numb) % mod;
    pow >>= 1;
   }

   return res;
}

int main(){
    get_input();

    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = target; j >= i; j--)
            dp[j] = (dp[j] + dp[j - i]) % mod;

    cout << (dp[target] * binpow(2, mod - 2)) % mod << '\n';
}
