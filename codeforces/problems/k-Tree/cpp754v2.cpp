#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1

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
const int mak = 2e5 + 7;

ll n, k, d;
vector<pll> dp;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> d;
    dp.resize(n + 1);
}
int main(){
    get_input();
    
    dp[0].fi = 1;
    dp[0].se = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k && i - j >= 0; j++)
            if(j < d){
                dp[i].fi += dp[i - j].fi; dp[i].fi %= mod;
                dp[i].se += dp[i - j].se; dp[i].se %= mod;
            }
            else{
                dp[i].se += dp[i - j].fi; dp[i].se %= mod;
                dp[i].se += dp[i - j].se; dp[i].se %= mod;
            }
    cout << dp[n].se << endl; 
}
