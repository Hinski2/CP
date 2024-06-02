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
const int mak = 1e6 + 7;
const ll p = 37;

string s;
ll power[mak], hsh[mak];

void make_powers(){
    power[0] = 1;
    for(int i = 1; i < mak; i++)
        power[i] = (power[i - 1] * p) % mod;
}

void make_hshs(){
    for(ll i = 1; i < s.size(); i++)
    hsh[i] = (hsh[i - 1] * p + s[i] - 'a' + 1) % mod;
}

ll get_hsh(ll l, ll len){
    ll r = l + len - 1;
    return (hsh[r] - (hsh[l - 1] * power[r - l + 1]) % mod + mod) % mod;
}

void wczytaj(){
    io; cin >> s;
    s = '#' + s;
}

bool check(ll hasz, ll len){
    for(int i = 2; i + len < s.size(); i++)
        if(get_hsh(i, len) == hasz) return true;
    return false;
}

int main(){
    wczytaj();
    // robienie hashy
    make_powers();
    make_hshs();

    ll n = s.size() - 1;
    for(int i = 1, j = 2, len = n - 1; len > 0; j++, len--){
        if(get_hsh(i, len) != get_hsh(j, len)) continue;
        if(check(get_hsh(i, len), len)){
            cout << s.substr(i, len) << endl;
            return 0;
        }
    }

    cout << "Just a legend" << endl;
}
