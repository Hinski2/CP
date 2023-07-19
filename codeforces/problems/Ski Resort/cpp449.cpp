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
const int mak = 2e5 + 7;

int t;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

ll solve(){
    int n, k, maks, cnt = 0;
    ll ans = 0;

    cin >> n >> k >> maks;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        if(x <= maks && ++cnt >= k)
            ans += cnt - k + 1;
        if(x > maks)
            cnt = 0;
    }

    return ans;
}

int main(){
    get_input();
    while(t--)
        cout << solve() << '\n';
}
