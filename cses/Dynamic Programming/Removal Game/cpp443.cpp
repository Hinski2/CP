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
const int mak = 5007;

int n;
vector<int> vec;

ll total;
ll dp[mak][mak];

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
        total += vec[i];
    }
}

int main(){
    get_input();

    for(int i = 0; i < n; i++)
        dp[1][i] = vec[i];

    for(int len = 2; len <= n; len++)
        for(int start = 0; start + len - 1 < n; start++)
            dp[len][start] = max(vec[start] - dp[len - 1][start + 1],
                vec[start + len - 1] - dp[len - 1][start]);

    cout << (total + dp[n][0]) / 2 << '\n';
}
