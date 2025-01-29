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
constexpr pair<T1, T2> operator+(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}

template <typename T1, typename T2>
constexpr pair<T1, T2>& operator+=(pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    p1.first += p2.first;
    p1.second += p2.second;
    return p1;
}

template <typename T1, typename T2>
constexpr pair<T1, T2> operator-(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}
template <typename T1, typename T2>
constexpr pair<T1, T2>& operator-=(pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    p1.first -= p2.first;
    p1.second -= p2.second;
    return p1;
}

template <typename T1, typename T2>
constexpr pair<T1, T2> operator*(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    return {p1.first * p2.first, p1.second * p2.second};
}
template <typename T1, typename T2>
constexpr pair<T1, T2>& operator*=(pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    p1.first *= p2.first;
    p1.second *= p2.second;
    return p1;
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

int solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    vector<int> va(n), vb(n);
    for(int i = 0; i < n; i++){
        va[i] = a[i] - '0';
        vb[i] = b[i] - '0';
    }

    int an[2] = {0}, bn[2] = {0}, x = 0;
    for(int i = 0; i < n; i++){
        an[va[i]]++;
        bn[vb[i]]++;
    }

    for(int i = n - 1; i >= 0; i--){
        if((va[i] ^ x) == vb[i]){
            an[vb[i]]--;
            bn[vb[i]]--;
            continue;
        }
        if(an[0] != an[1]) return 0;
        x ^= 1;
        an[vb[i]]--;
        bn[vb[i]]--;
    }

    return 1;
}

int main(){
    io; int t; cin >> t;
    while(t--)
        cout << yn << endl;
}
