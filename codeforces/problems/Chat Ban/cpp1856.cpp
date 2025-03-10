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

int lines(int mid, int k){
    int ans = 0;
    int x = min(k - 1, mid);
    ans += x * (x + 1) / 2;
    mid -= x;

    if(mid){
        ans += k;
        mid--;
    }

    ans += k * (k - 1) / 2;
    x = k - 1 - mid;
    ans -= x * (x + 1) / 2;
    return ans;
}

int solve(){
    int k, x; cin >> k >> x;
    int l = 0, r = 2 * k - 1; // ile lini wypisze 
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(lines(mid - 1, k) + 1 <= x) l = mid;
        else r = mid - 1;
    }

    return l;
}

signed main(){
    io; int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
