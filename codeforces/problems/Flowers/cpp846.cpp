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
const int mak = 1e5 + 7;

int k;
ll dp[mak][2];
ll sum[mak];

void make_dp(){
    dp[1][0] = 1;
    dp[k][1]++;
    
    for(int i = 2; i < mak; i++){
        if(i - k >= 0){
            dp[i][1] += dp[i - k][1];
            dp[i][1] += dp[i - k][0];
            dp[i][1] %= mod;
        }

        dp[i][0] += dp[i - 1][1];
        dp[i][0] += dp[i - 1][0];
        dp[i][0] %= mod;
    }
}

void make_sum(){
    for(int i = 1; i < mak; i++)
        sum[i] = dp[i][1] + dp[i][0] + sum[i - 1], sum[i] %= mod;
}

int main(){
    io; int t; cin >> t >> k;
    make_dp();
    make_sum();

    while(t--){
        int a, b; cin >> a >> b;
        ll ans = (sum[b] - sum[a - 1] + mod) % mod;
        cout << ans << endl;
    }

}
