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
        os << u;
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
    vector<int> a(n), b(n); cin >> a >> b;

    if(accumulate(a.begin(), a.end(), 0) != accumulate(b.begin(), b.end(), 0)) {
        cout << -1 << endl;
        return;
    }

    vector<pii> ans;
    for(int i = 0; i < n; i++) {
        while(a[i] < b[i]) {
            bool f = 0;
            for(int j = 0; j < n; j++) {
                if(a[j] > b[j]) {
                    ans.pb({j + 1, i + 1});
                    a[i]++, a[j]--;
                    f = 1;
                    break;
                }
            }
            if(f == 0) break;
        }
    }

    bool ok = true;
    for(int i = 0; i < n; i++)
        if(a[i] != b[i]) ok = false;

    if(ok) {
        cout << ans.size() << endl;
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
