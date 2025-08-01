#include <bits/stdc++.h>
using namespace std;

// geometry
template<typename T>
ostream& operator<<(ostream& os, const pair<T, T>& p) {
    os << p.first << ' ' << p.second << ' ';
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

int n, heroes[mak], sum;

inline int f(int idx, int x, int y) {
    return max(0ll, x - heroes[idx]) + max(0ll, y - sum + heroes[idx]);
}

int solve() {
    int x, y; cin >> x >> y;

    int ans, l = 1, r = n;
    while(l < r) {
        int mid = (l + r) / 2;
        if(heroes[mid] >= x) r = mid;
        else l = mid + 1;
    }

    // plan a
    ans = f(l, x, y);

    // plan b
    if(l > 1) ans = min(ans, f(l - 1, x, y));

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> heroes[i];

    // preproc
    sum = accumulate(heroes + 1, heroes + n + 1, 0ll);
    sort(heroes + 1, heroes + n + 1);

    // querries
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
