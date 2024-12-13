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

bool cmp(const pair<char, int> &a, const pair<char, int> &b){
    if(a.fi != b.fi) return a.fi < b.fi;
    return a.se > b.se;
}

void solve(){
    string s; cin >> s; 
    char first = s[0], last = s[s.size() - 1];

    vector<pair<char, int>> v(s.size());
    for(int i = 0; i < s.size(); i++)
        v[i] = {s[i], i + 1};

    if(first <= last){
        sort(all(v));
        int l = inf, r = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i].fi == first) l = min(l, i);
            if(v[i].fi == last) r = max(r, i);
        }

        cout << abs(first - last) << ' ' << r - l + 1 << endl;
        for(int i = l; i <= r; i++)
            cout << v[i].se << ' ';
        cout << endl;
    }
    else{
        sort(all(v), cmp);
        int l = 0, r = inf;
        for(int i = 0; i < v.size(); i++){
            if(v[i].fi == first) l = max(l, i);
            if(v[i].fi == last) r = min(r, i);
        }

        cout << abs(first - last) << ' ' << l - r + 1 << endl;
        for(int i = l; i >= r; i--)
            cout << v[i].se << ' ';
        cout << endl;
    }
}

int main(){
    io; int t; cin >> t;
    while(t--)
        solve();
}
