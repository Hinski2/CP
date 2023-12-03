#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
    for(const auto &u: v){
        os << u << ' ';
    }
    return os;
}
template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& u : v){
        is >> u;
    }
    return is;
}

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define yn (solve() ? "YES" : "NO")

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

int n, m;
vector<vector<int>> G;
vector<bool> vis;
bool cycle = false;

void dfs(int v, int p = -1){
    vis[v] = true;
    for(auto u: G[v]){
        if(u == p) continue;
        if(vis[u]){
            cycle = true;
            return;
        }
        dfs(u, v);
    }
}

int main(){
    io; cin >> n >> m;
    G.resize(n + 1);
    vis.reserve(n + 1);

    for(int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    for(int i = 1; i <= n && n - 1 == m; i++){
        if(G[i].size() == n - 1){
            cout << "star topology\n";
            return 0;
        }
    }

    if(m == n - 1){
        int single = 0, doub = 0, other = 0;
        for(int i = 1; i <= n; i++){
            if(G[i].size() == 1) single++;
            else if(G[i].size() == 2) doub++;
            else other++;
        }

        if(single == 2 && !other){
            cout << "bus topology\n";
            return 0;
        }
    }

    cycle = true;
    for(int i = 1; i <= n; i++)
        if(G[i].size() != 2) cycle = false;
    if(cycle){
        cout << "ring topology\n";
        return 0;
    }

    cout << "unknown topology\n";
}
