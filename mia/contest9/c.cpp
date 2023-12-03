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

struct vert
{
    int gdzie;
    int idx;
};

int n, m;
vector<vector<vert>> G;
vector<int> ans;
vector<bool> vis;

void solve(){
    int k = 0;
    cin >> n >> m;
    G.resize(n + 1);
    ans.resize(m + 1);

    for(int i = 1, a, b; i <= m; i++){
        cin >> a >> b;
        G[a].pb({b, i});
        G[b].pb({a, i});
    }

    //klika
    if(n * (n - 1) / 2 == m){
        cout << 3 << endl;
        for(auto u: G[1])
            ans[u.idx] = 1;
        ans[G[1][0].idx] = 3;
    }
    else{
        cout << 2 << endl;
        int target = 0;
        for(int i = 1; i <= n; i++)
            if(G[i].size() != n - 1) target = i;
        
        for(auto u: G[target])
            ans[u.idx] = 1;
    }

    for(int i = 1; i <= m; i++)
        if(ans[i]) cout << ans[i] << ' ';
        else cout << 2 << ' ';
    cout << endl;
}

int main(){
    io; int t; cin >> t;
    while(t--){
        for(auto &u: G)
            u.clear();
        G.clear();
        ans.clear();

        solve();
    }
}
