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

int n;
vector<int> v;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n);
    for(auto &u: v) cin >> u;
    for(int i = 0, x; i < n; i++) cin >> x, v[i] -= x;
}
int main(){
    get_input();
    sort(all(v));

    ll ans = 0;
    for(int i = 0; i < n; i++){
        auto itr = lower_bound(v.begin(), v.end(), -(v[i] - 1));
        ans += v.end() - itr;
        if(v[i] > 0) ans--;
    }

    cout << ans / 2 << endl;
}