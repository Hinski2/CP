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
ll line[mak][2], dp[mak][2];

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> line[i][0];
    for(int i = 1; i <= n; i++) cin >> line[i][1];
}
int main(){
    get_input();
    dp[1][0] = line[1][0];
    dp[1][1] = line[1][1];
    for(int i = 2; i <= n; i++){
        dp[i][0] = max(dp[i - 1][1], max(dp[i - 2][0], dp[i - 2][1])) + line[i][0];
        dp[i][1] = max(dp[i - 1][0], max(dp[i - 2][1], dp[i - 2][0])) + line[i][1];
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
}
