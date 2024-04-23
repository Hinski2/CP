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

int n, k;
vector<vector<int>> G;
vector<ll> deep;
vector<ll> sajz;

void wczytaj(){
    io;cin >> n >> k;
    G.resize(n);
    for(int i = 1, a, b; i < n; i++){
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    deep.resize(n);
    sajz.resize(n);
}

void dfs(int v, ll d, int p = -1){
    deep[v] = d;
    sajz[v] = 1;

    for(auto u: G[v]){
        if(u == p) continue;
        dfs(u, d + 1, v);

        sajz[v] += sajz[u];
    }
}

int main(){
    wczytaj();
    dfs(0, 1);

    vector<ll> elem(n);
    for(int i = 0; i < n; i++)
        elem[i] = sajz[i] - deep[i];

    sort(all(elem), greater<ll>());

    ll sum = 0;
    for(int i = 0; i < n - k; i++)
        sum += elem[i];
    cout << sum << endl;
}
