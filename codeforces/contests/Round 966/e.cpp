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
#define int ll

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

int solve(){
    int n, m, k; cin >> n >> m >> k;
    int w; cin >> w;
    vector<int> gor(w); cin >> gor;

    vector<vector<int>> v(n + 2, vector<int>(m + 2));
    for(int i = 1; i + k - 1 <= n; i++)
        for(int j = 1; j + k - 1 <= m; j++){
            v[i][j] += 1;
            v[i + k][j] -= 1;
            v[i][j + k] -= 1;
             v[i + k][j + k] += 1;
        }
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            v[i][j] += v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1];
    
    vector<int> pos;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            pos.pb(v[i][j]);
    
    sort(all(pos), greater<>());
    sort(all(gor), greater<>());
    int ans = 0;
    for(int i = 0; i < w; i++)
        ans += gor[i] * pos[i];

    return ans;
}

signed main(){
    io; int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}