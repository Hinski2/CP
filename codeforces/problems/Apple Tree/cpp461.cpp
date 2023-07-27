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
const int mak = 2e5 + 7;

int t;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

void root(int v, vector<vector<int>> &G, vector<int> &ways, int p = 1){
    if(G[v].size() == 1 && v != 1) ways[v] = 1;
    
    for(auto u: G[v]){
        if(u == p) continue;
        root(u, G, ways, v);
        ways[v] += ways[u];
    }
}

void solve(){
    int n, q;
    cin >> n;

    vector<vector<int>> G(n + 1);
    vector<int> ways(n + 1);

    for(int i = 1, a, b; i < n; i++){
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    cin >> q;
    root(1, G, ways);
    for(int i = 0, a, b; i < q; i++){
        cin >> a >> b;
        cout << 1LL * ways[a] * ways[b] << '\n';
    }
}

int main(){
    get_input();
    while(t--)
        solve();
}
