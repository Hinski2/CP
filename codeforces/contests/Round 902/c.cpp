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

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

ll solve(){
    ll n, m; cin >> n >> m;
    vector<int> ans(5);
    for(int modulo = 0; modulo <= m; modulo++){
        set<int> s;
        s.insert(modulo);
        // cout << modulo << ' ';
        int next = modulo;
        for(int i = n; i >= 1; i--){
            next = next % i;
            s.insert(next);
            // cout << next << ' ';
        }
        // cout << endl;
        ans[s.size()]++;
    }
    for(auto u: ans) cout << u << ' ';
    cout << endl;

    return 0;
}
int main(){
    get_input();
    solve();
}
