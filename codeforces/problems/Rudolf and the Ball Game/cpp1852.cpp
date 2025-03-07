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

int clock(int start, int dist, int n){
    return (start + dist - 1) % n + 1;
}

int counterclock(int start, int dist, int n){
    return (start - dist - 1 + n) % n + 1;
}

void solve(){
    int n, m, x; cin >> n >> m >> x;
    int now = 0;

    set<int> s[2];
    s[0].insert(x);

    while(m--){
        int dist; char c; cin >> dist >> c;
        if(c == '0'){
            for(auto u: s[now])
                s[now ^ 1].insert(clock(u, dist, n));
        }
        else if(c == '1'){
            for(auto u: s[now])
                s[now ^ 1].insert(counterclock(u, dist, n));
        }
        else{
            for(auto u: s[now])
                s[now ^ 1].insert(clock(u, dist, n));
            for(auto u: s[now])
                s[now ^ 1].insert(counterclock(u, dist, n));
        }

        s[now].clear();
        now ^= 1;
    }

    cout << s[now].size() << endl;
    for(auto u: s[now])
        cout << u << ' ';
    cout << endl;
}

signed main(){
    io; int t; cin >> t;
    while(t--)
        solve();
}
