#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

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
const ll mak = 30;

int t;
vector<int>vec(mak);

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;

    for(int i = 0; i < mak && (1 << i) < inf; i++)
        vec[i] = 1 << i;
}

int solve(){
    ll n, k, ans = 0;
    cin >> k >> n;
    n = min(n, mak);

    return min(1LL << n, k + 1);
}

int main(){
    get_input();
    while(t--)
        cout << solve() << '\n';
}
