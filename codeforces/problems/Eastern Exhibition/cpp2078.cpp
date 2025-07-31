#include <bits/stdc++.h>
using namespace std;


// geometry 
template<typename T> ostream& operator<<(ostream& os, const pair<T, T>& p) {
    os << p.first << ' ' << p.second << '\n';
    return os;
}

template<typename T> istream& operator>>(istream& is, pair<T, T>& p) {
    is >> p.first >> p.second;
    return is;
}


template<typename T> pair<T, T> operator + (const pair<T, T> &a, const pair<T, T> &b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

template<typename T> pair<T, T> operator - (const pair<T, T> &a, const pair<T, T> &b) {
    return make_pair(a.first - b.first, a.second - b.second);
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

template<typename T> long long sum_element(const vector<T> &v) {
    long long s = 0;
    for(auto u: v) s += u;
    return s;
}

// max / min
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

// struct Radious {
//     pii ul, ur, dl, dr;

//     int area() {
//         int x = ur.fi - ul.fi + 1;
//         int y = ul.se - dl.se + 1;

//         if(x <= 0 or y <= 0) return 0;
//         return x * y;
//     }

//     Radious operator * (Radious &other) {

//     }

//     Radious(pii pt, int r) {
//         ul = pt + make_pair(-r, r);
//         ur = pt + make_pair(r, r);
//         dl = pt + make_pair(-r, -r);
//         dr = pt + make_pair(r, -r);
//     }
// };

int solve() {
    int n; cin >> n;
    vector<pii> pts(n); cin >> pts;
    // for(auto &u: pts)
    //     cin >> u;

    sort(all(pts), [](const pii& a, const pii& b) -> bool {
        if(a.fi != b.fi) return a.first < b.first;
        return false;
    });

    int x = pts[n / 2].fi - pts[(n - 1) / 2].fi + 1;
    sort(all(pts), [](const pii& a, const pii& b) -> bool {
        if(a.se != b.se) return a.se < b.se;
        return false;
    });

    int y = pts[(n) / 2].se - pts[(n - 1) / 2].se + 1;
    return x * y;
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
