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

vector<vector<int>> solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m)); cin >> v;
    vector<pii> vec = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool changed = true;
    int i = 0, j = 0;
    while(changed){
        changed = false;
        for(; i < n && !changed;i++, j = 0){
            for(; j < m && !changed;j++){
                int x, y;
                bool git = true;
                for(auto u: vec){
                    x = i + u.first; if(x < 0 || x >= n) continue;
                    y = j + u.second; if(y < 0 || y >= m) continue;
                    if(v[x][y] >= v[i][j]) git = false;
                    if(!git) break;
                }

                if(git){
                    changed = true;
                    int maxi = 0, x, y;
                    for(auto u: vec){
                        x = i + u.first; if(x < 0 || x >= n) continue;
                        y = j + u.second; if(y < 0 || y >= m) continue;
                        maxi = max(maxi, v[x][y]);
                    }
                    v[i][j] = maxi;
                    i--;
                }
            }
        }
    }
    return v;
}

int main(){
    io; int t; cin >> t;
    while(t--){
        vector<vector<int>> v = solve();
        for(auto u: v)
            cout << u << endl;
    }

}