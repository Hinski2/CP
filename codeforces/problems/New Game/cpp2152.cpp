#include <bits/stdc++.h>
using namespace std;
 
// geometry
template<typename T>
ostream& operator<<(ostream& os, const pair<T, T>& p) {
    os << p.first << ' ' << p.second << '\n';
    return os;
}
 
template<typename T> 
istream& operator>>(istream& is, pair<T, T>& p) {
    is >> p.first >> p.second;
    return is;
}
 
template<typename T>
pair<T, T> operator + (const T& a, const T& b) {
    return make_pair(a.first + b.first, a.second + b.second);
}
 
template<typename T>
pair<T, T> operator - (const T& a, const T& b) {
    return make_pair(a.first - b.first, a.second - b.second);
}
 
template<typename T>
T operator * (const T& a, const T& b) {
    return a.first * b.second - a.second * b.first;
}
 
template<typename T>
T cross_product(const T& a, const T& b) {
    return a * b;
}
 
template<typename T>
T cross_product(const T& a, const T& b, const T& c) {
    return (b - a) * (c - a);
}
 
// vector
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const auto &u: v) {
        os << u << ' ';
    }
    return os;
}
 
template<typename T> istream& operator>>(istream& is, vector<T>& v) {
    for(auto& u : v) {
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
#define yn (solve() ? "YES" : "NO")
#define int ll
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;
 
int solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n); cin >> v;
    sort(all(v));
 
    vector<pii> numbs;  // numb, amm
    numbs.pb({v[0], 1});
    for(int i = 1; i < n; i++) 
        if(v[i - 1] == v[i]) numbs.back().se++;
        else numbs.push_back({v[i], 1});
 
    int cnt = 1, now = numbs[0].se, ans = numbs[0].se;
    for(int i = 1; i < numbs.size(); i++) {
        if(numbs[i - 1].fi + 1 == numbs[i].fi) {
            now += numbs[i].se;
            cnt++;
        } else {
            now = numbs[i].se;
            cnt = 1;
        }
 
        if(cnt > k) {
            cnt = k;
            now -= numbs[i - k].se;
        }
 
        ans = max(ans, now);
    }
    return ans; 
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}