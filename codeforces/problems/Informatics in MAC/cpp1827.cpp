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
typedef tree<int,null_type, less<int>, rb_tree_tag,\
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,\
tree_order_statistics_node_update> ordered_multiset;
//erase: oms.erase(oms.upper_bound(value))

constexpr int mod = 1e9 + 7;
constexpr int inf = 1e9 + 7;
constexpr int mak = 2e5 + 7;

void solve(){
    int n; cin >> n;
    vector<int> v(n); cin >> v;
    map<int, int> m; 
    for(auto u: v) m[u]++;

    if(m[0] == 0){
        cout << n << endl;
        for(int i = 1; i <= n; i++)
            cout << i << ' ' << i << endl;
        return;
    }

    int t = 1;
    while(m[t] != 0){
        if(m[t] == 1){
            cout << -1 << endl;
            return;
        }
        t++;
    }

    vector<pii> ans;
    set<int> s;
    int l = 0;
    for(int i = 0; i < n; i++){
        if(v[i] < t) s.insert(v[i]);
        if(s.size() == t){
            ans.pb({l + 1, i + 1});
            s.clear();
            l = i + 1;
        }

        if(ans.size() == 2) break;
    }

    if(ans.size() != 2){
        cout << -1 << endl;
        return;
    }
    cout << 2 << endl;
    cout << ans[0].fi << ' ' << ans[0].se << endl;
    cout << ans[1].fi << ' ' << n << endl;
}

signed main(){
    io; int t; cin >> t;
    while(t--)
        solve();
}
