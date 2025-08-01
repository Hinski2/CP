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
    string s; cin >> s;

    // test
    if(count(all(s), ')') != count(all(s), '(')) {
        cout << -1 << endl;
        return;
    }

    int cnt = 0, l = 0;
    vector<pii> occ;

    auto positive = [&](pii pos) {
        int cnt = 0;
        for(int i = pos.fi; i <= pos.se; i++) {
            if(s[i] == '(') cnt++;
            else cnt--;

            if(cnt < 0) return false;
        }
        
        return true;
    };


    for(int i = 0; i < n; i++) {
        if(s[i] == '(') cnt++;
        else cnt--;

        if(cnt == 0) {
            occ.pb({l, i});
            l = i + 1;
        }
    }

    int last = positive(occ.front()), colors = 0;
    vector<int> ans(n);

    int positive_color = 0, negative_color = 0;

    auto color = [&](pii pos, int color) {
        for(int i = pos.fi; i <= pos.se; i++)
            ans[i] = color;
    };

    for(auto u: occ) {
        int pos = positive(u);

        if(pos) {
            if(!positive_color) positive_color = ++colors;
            color(u, positive_color);
        } else {
            if(!negative_color) negative_color = ++colors;
            color(u, negative_color);
        }
    }

    cout << colors << endl;
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
