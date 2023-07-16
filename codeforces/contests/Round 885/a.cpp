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
const int mak = 105;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void solve(){
    int n, m, k;
    bool ans = true;

    cin >> n >> m >> k;

    pii vika;
    cin >> vika.fi >> vika.se;

    for(int i = 1, a, b; i <= k; i++){
        cin >> a >> b;
        
        int dist = abs(vika.fi - a) + abs(vika.se - b);
        if(dist % 2 == 0) ans = false;
    }

    if(ans) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    get_input();

    int t;
    cin >> t;

    while(t--)
        solve();
}
