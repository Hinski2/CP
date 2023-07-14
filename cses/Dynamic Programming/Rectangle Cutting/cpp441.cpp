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
const int mak = 507;

int dp[mak][mak];
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

}

int cut(int n, int m){
    if(n == m) return 0;
    if(n < m) swap(n, m); //n is bigger;
    if(dp[n][m]) return dp[n][m];

    int ans = inf;
    for(int i = 1; i <= n / 2; i++)
        ans = min(ans, cut(i, m) + cut(n - i, m));
    for(int i = 1; i <= m / 2; i++)
        ans = min(ans, cut(n, i) + cut(n, m - i));

    return dp[n][m] = ans + 1;
}

int main(){
    get_input();

    int n, m;
    cin >> n >> m;

    cout << cut(n, m) << '\n';
}
