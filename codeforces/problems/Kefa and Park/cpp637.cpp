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

int n, m, ans;
vector<vector<int>> G;
vector<bool> cat;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    G.resize(n + 1), cat.resize(n + 1);
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        cat[i] = x ? 1 : 0;
    }
    for(int i = 1, a, b; i < n; i++){
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
}

void dfs(int v, int pc, int p = -1){
    int c = cat[v] ? pc + 1 : 0;
    if(c > m) return;

    if(G[v].size() == 1 && v != 1) ans++;
    for(auto u: G[v])
        if(u != p) dfs(u, c, v);
}
int main(){
    get_input();
    dfs(1, 0);
    cout << ans << endl;
}
