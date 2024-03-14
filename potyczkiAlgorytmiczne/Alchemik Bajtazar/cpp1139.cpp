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
const int mak = 30'005;

int n, m[2];
vector<string> ans;
vector<set<int>> s[2];
vector<int> vis;
vector<vector<int>> G[2]; 

void wczytaj(){
    io; cin >> n >> m[0];
    vis.resize(n + 1);
    G[0].resize(n + 1);
    s[0].resize(n + 1);

    for(int i = 0; i < m[0]; i++){
        int a, b; cin >> a >> b;
        G[0][a].pb(b);
        G[0][b].pb(a);
        s[0][a].insert(b);
        s[0][b].insert(a);
    }

    cin >> m[1];
    G[1].resize(n + 1);
    s[1].resize(n + 1);
    for(int i = 0; i < m[1]; i++){
        int a, b; cin >> a >> b;
        G[1][a].pb(b);
        G[1][b].pb(a);
        s[1][a].insert(b);
        s[1][b].insert(a);
    }
}
void usun(int a, int b, int t){
    ans.pb("- " + to_string(a) + " " + to_string(b) + "\n");
    s[t][a].erase(b);
    s[t][b].erase(a);
} 

void dodaj(int a, int b, int t){
    ans.pb("+ " + to_string(a) + " " + to_string(b) + "\n");
    G[t][a].pb(b);
    G[t][b].pb(a);
    s[t][a].insert(b);
    s[t][b].insert(a);
} 

void dfs(int v){
    vis[v] = 1;
    if(v != 1 && s[0][v].count(1) == 0) dodaj(1, v, 0);

    for(auto u: G[0][v]){
        if(vis[u] == 1) continue;
        dfs(u);
    }
}

void dfs2(int v){
    vis[v] = 2;
    for(auto u: G[0][v]){
        if(vis[u] == 2) continue;
        dfs2(u);
    }

    if(s[1][v].count(1) == 0 && v != 1) usun(1, v, 0);
}

int main(){
    //wczytani danych
    wczytaj();

    //wszystkie wierzchołki są połączone z 1
    dfs(1);

    //dodaje to co potrzemuje
    for(int i = 2; i <= n; i++){
        for(auto u: G[1][i])
            if(s[0][i].count(u) == 0)
                dodaj(i, u, 0);
    }

    //usówam te u w gdzie u i w != 1
    for(int i = 2; i <= n; i++){
        for(auto u: G[0][i])
            if(u != 1 && s[1][i].count(u) == 0)
                usun(i, u, 0);
    }

    //usówam połączenia z 1
    dfs2(1);

    //wypisanie
    cout << ans.size() << endl;
    for(auto u: ans)
        cout << u;
}
