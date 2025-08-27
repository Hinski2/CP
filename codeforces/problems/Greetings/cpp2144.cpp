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

bool cmp(const pii& a, const pii& b) {
    return a.se < b.se;
}

struct Tree {
    vector<int> vals;
    int base = 1;

    Tree(int n) {
        vals.resize(4 * n);
        while(base * 4 < vals.size())
            base *= 2;
    }

    void insert(int idx) {
        idx += base;
        while(idx) {
            vals[idx]++;
            idx /= 2;
        }
    }

    int cnt(int l, int r) {
        l += base;
        r += base;

        int ans = vals[l];
        if(l != r) ans += vals[r];

        while(l / 2 != r / 2) {
            if(l % 2 == 0) ans += vals[l + 1];
            if(r % 2 == 1) ans += vals[r - 1];

            r /= 2;
            l /= 2;
        }

        return ans;
    }
};

int solve() {
    int n; cin >> n;
    vector<pii> v(n); cin >> v;

    // compression
    map<int, int> mapa;
    for(auto &[a, b]: v)
        mapa[a]++, mapa[b]++;
    int idx = 0;
    for(auto &[key, val]: mapa)
        val = idx++;
    for(auto &[a, b]: v)
        a = mapa[a], b = mapa[b];

    // nex step
    Tree tree(2 * n);
    int ans = 0;

    sort(all(v), cmp);
    for(auto &[a, b]: v) {
        ans += tree.cnt(a, b);
        tree.insert(a);
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
