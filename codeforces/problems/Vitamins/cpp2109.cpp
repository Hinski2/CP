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

struct S {
    string s;
    int x;
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<string, int> mapa;

    mapa["A"] = mapa["B"] = mapa["C"] = inf;
    mapa["AB"] = mapa["AC"] = mapa["BC"] = inf;
    mapa["ABC"] = inf;

    for(int i = 0; i < n; i++) {
        int x; string s; cin >> x >> s;
        sort(all(s));
        mapa[s] = min(mapa[s], x);
    }

    int ans = inf;
    ans = min(ans, mapa["ABC"]);
    vector<string> let = {"AB", "AC", "BC"};
    for(auto a: let) {
        for(auto b: let) {
            if(a == b) continue;
            ans = min(ans, mapa[a] + mapa[b]);
        }
    }

    ans = min(ans, mapa["AB"] + mapa["C"]);
    ans = min(ans, mapa["BC"] + mapa["A"]);
    ans = min(ans, mapa["AC"] + mapa["B"]);
    ans = min(ans, mapa["A"] + mapa["B"] + mapa["C"]);

    cout << (ans == inf ? -1 : ans) << endl;
}
