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
const int mak = 1e6 + 7;

ll dp[mak][2];

ll process(int n, int type){
    if(n == 1) return 1;
    if(dp[n][type]) return dp[n][type];

    if(type == 0){
        dp[n][type] += 2 * process(n - 1, 0);
        dp[n][type] += process(n - 1, 1);
        dp[n][type] %= mod;
    }
    else{
        dp[n][type] += process(n - 1, 0);
        dp[n][type] += 4 * process(n - 1, 1);
        dp[n][type] %= mod;
    }

    return dp[n][type];
} 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        ll ans = process(n, 0) + process(n, 1); ans %= mod;
        cout << ans << '\n';
    }
}
