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
const int mak = 105;

int n;
vector<int> v;
vector<vector<int>> dp(3, vector<int>(mak, 0));

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];
}
int main(){
    get_input();

    for(int i = 1; i <= n; i++){
        int nothing = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
        int last2 = max(dp[0][i - 2], max(dp[1][i - 2], dp[2][i - 2]));
        if(i < 2) last2 = 0;

        dp[0][i] = max(nothing, last2);
        if(v[i] == 1 || v[i] == 3) dp[1][i] = max(last2, max(dp[2][i - 1], dp[0][i - 1])) + 1;
        if(v[i] == 2 || v[i] == 3) dp[2][i] = max(last2, max(dp[1][i - 1], dp[0][i - 1])) + 1;
    }

    cout << n - max(dp[0][n], max(dp[1][n], dp[2][n])) << endl;
}
