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
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    return make_pair(p1.first + p2.first, p1.second + p2.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    return make_pair(p1.first - p2.first, p1.second - p2.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator*(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    return make_pair(p1.first * p2.first, p1.second * p2.second);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << p.first << ' ' << p.second;
    return os;
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
    is >> p.first >> p.second;
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
inline bool ok_coord(int x, int y){
    if(x == 0 || y == 0) return 0;
    return x <= n && y <= m;
}



int solve(){
    cin >> n >> m;
    int num_of_good = 0;
    vector<vector<char>> G(n + 1, vector<char>(m + 1));
    vector<pii> v = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> G[i][j];
            if(G[i][j] == 'G') num_of_good++;
        }
    }

    if(G[n][m] == 'B') return 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(G[i][j] != 'B') continue;
            for(auto [x, y]: v){
                x += i, y += j;
                if(!ok_coord(x, y)) continue;
                if(G[x][y] == 'G') return 0;
                if(x == n && y == m && num_of_good) return 0;
                if(G[x][y] != 'B') G[x][y] = '#';
            }
        }
    }

    int met = 0;
    queue<pii> q; q.push({n, m});
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));

    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();
        if(vis[i][j]) continue;
        else vis[i][j] = true;

        if(G[i][j] == 'G') met++;
        for(auto [x, y]: v){
            x += i, y += j;
            if(!ok_coord(x, y) || vis[x][y] ||  G[x][y] == '#') continue;
            q.push({x, y});
        }
    }

    return met == num_of_good;
}

int main(){
    io; int t; cin >> t; 
    while(t--)
        cout << yn << endl;
}
