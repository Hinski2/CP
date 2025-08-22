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

void solve() {
    int n; cin >> n;
    vector<int> v(n); cin >> v;
    sort(all(v));

    vector<int> ans(2 * n);
    int v_idx = 0;
    for(int i = 0; i < (n + 1) / 2; i++, v_idx++)
        ans[i * 2] = v[v_idx];

    for(int i = 0; v_idx < n; i++, v_idx++)
        ans[i * 2 + 1] = v[v_idx];

    for(int i = 0; i < n; i++)
        ans[i + n] = ans[i];
    
    bool ok = true;
    for(int i = 1; i + 1 < 2 * n; i++) {
        if(ans[i - 1] < ans[i] and ans[i] > ans[i + 1]) continue;
        if(ans[i - 1] > ans[i] and ans[i] < ans[i + 1]) continue;
        ok = false;
    }

    if(ok) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
