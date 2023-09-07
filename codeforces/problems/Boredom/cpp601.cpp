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
const int mak = 1e5 + 7;

int n;
vector<ll> no, dp;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    no.resize(mak);
    dp.resize(mak);
    for(int i = 0, x; i < n; i++){
        cin >> x;
        no[x]++;
    }
}
int main(){
    get_input();
    dp[1] = no[1];
    dp[2] = no[2] * 2;
    dp[3] = no[3] * 3 + dp[1];
    for(int i = 4; i < mak; i++)
        dp[i] = no[i] * i + max(dp[i - 3], dp[i - 2]);

    ll ans = 0;
    for(auto u: dp)
        ans = max(ans, u);
    cout << ans << endl;
}
