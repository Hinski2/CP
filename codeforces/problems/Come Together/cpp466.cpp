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

int solve(){
    pii a, b, c;
    cin >> a.fi >> a.se;
    cin >> b.fi >> b.se;
    cin >> c.fi >> c.se;
    
    int u = max(min(c.se - a.se, b.se - a.se), 0); 
    int d = max(min(a.se - c.se, a.se - b.se), 0);
    int l = max(min(c.fi - a.fi, b.fi - a.fi), 0);
    int r = max(min(a.fi - c.fi, a.fi - b.fi), 0);

    return l + r + u + d + 1;
}

int main(){
    get_input();
    while(t--)
        cout << solve() << endl;
}
