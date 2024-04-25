#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
    for(const auto &u: v){
        os << u << ' ';
    }
    return os;
}
template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& u : v){
        is >> u;
    }
    return is;
}

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define yn (solve() ? "YES" : "NO")

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
const int mak = 2050;

ll dp[mak][mak];
vector<ll> d[mak];

ll count(ll x, ll k){
    if(k == 1) return 1;
    else if(dp[x][k] != -1) return dp[x][k];

    ll ans = 0;
    for(auto u: d[x])
        ans = (ans + count(u, k - 1)) % mod;

    return dp[x][k] = ans;
} 

int main(){
    ll n, k;
    io; cin >> n >> k;
    for(int i = 0; i < mak; i++)
        for(int j = 0; j < mak; j++)
            dp[i][j] = -1;
    
    for(int i = 1; i < mak; i++)
        for(int j = i; j < mak; j += i)
            d[j].pb(i);
    
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans = (ans + count(i, k)) % mod;
    
    cout << ans << endl;
}
