#include <bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream& os, const pair<T, T>& p) {
    os << p.first << ' ' << p.second << '\n';
    return os;
}

template<typename T> istream& operator<<(istream& os, const pair<T, T>& p) {
    os >> p.first >> p.second;
    return os;
}

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

template<typename T> long long sum_element(const vector<T> &v) {
    long long s = 0;
    for(auto u: v) s += u;
    return s;
}

template<typename T> T max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

template<typename T, typename ... Args> T max(const T& a, const Args& ... args) {
    return max(a, max(args...));
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
    int n; cin >> n;
    vector<int> v(n); cin >> v;
    map<int, int> mapa;
    for(auto u: v)
        mapa[u]++;

    if(mapa[0]) {
        return n - mapa[0];
    } else {
        for(auto [k, v]: mapa) {
            if(v >= 2) return n;
        }

        return n + 1;
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
