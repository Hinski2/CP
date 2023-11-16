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
vector<vector<int>> G;
vector<int> deep;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    G.resize(n + 1); deep.resize(n + 1);
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        if(x == -1) continue;
        G[x].pb(i);
    }
}

int dfs(int v){
    deep[v] = 1;
    for(auto u: G[v]){
        if(!deep[u]) dfs(u);
        deep[v] = max(deep[v], deep[u] + 1);
    }

    return deep[v];
}
int main(){
    get_input();

    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(!deep[i]) ans = max(ans, dfs(i));
    
    cout << ans << endl;
}
