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

void solve(){
    int n, ans = 1;
    vector<int> value, band;

    cin >> n;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        value.pb(x);
        band.pb(x);
    }

    for(int i = n - 2; i >= 0; i--)
        band[i] &= band[i + 1];

    if(band[0]){
        cout << ans << '\n';
        return;
    }

    int _and = value[0];
    for(int i = 0; i < n - 1; i++){
        _and &= value[i];

        if(_and == 0 && band[i + 1] == 0){
            ans++;
            _and = value[i + 1];
        }
    }

    cout << ans << '\n';
}

int main(){
    get_input();

    while(t--)
        solve();
}
