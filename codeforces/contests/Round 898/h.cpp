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

int t, run_to = 0;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

void dfs(int v, vector<vector<int>> &G, vector<bool> &vis, int p = -1){
    if(run_to) return;
    if(vis[v]){
        run_to = v;
        return;
    }

    for(auto u: G[v]){
        if(u != p && !run_to) dfs(u, G, vis, v);
    }
}

int dist(int s, int e, vector<vector<int>> &G){
    int dis = 0;
    queue<pii> q;
    q.push({s, 0});

    vector<bool> vis(G.size());
    while(!q.empty()){
        int v = q.front().fi;
        int d = q.front().se;
        q.pop();
        if(vis[v]) continue;
        vis[v] = true;

        if(v == e) return d;
        for(auto u: G[v])
            if(!vis[u]) q.push({u, d + 1});
    }

    return 0;
}

bool solve(){
    int n, Marc, Val;
    cin >> n >> Marc >> Val;

    vector<vector<int>> G(n + 1);
    vector<bool> vis(n + 1);
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    run_to = 0;
    dfs(Val, G, vis);

    int dis_Marc = dist(Marc, run_to, G);
    int dist_Val = dist(Val, run_to, G);

    return dist_Val < dis_Marc;
}

int main(){
    get_input();
    while(t--)
        cout << (solve() ? "YES" : "NO") << endl;
}
