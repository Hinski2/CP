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

struct Point {
    int idx;
    int pos;
    int weight;
};

bool cmp_pos(const Point& a, const Point& b) {
    if(a.pos != b.pos) return a.pos < b.pos;
    return a.weight < b.weight;
}

bool cmp_weight(const Point& a, const Point& b) {
    if(a.weight != b.weight) return a.weight < b.weight;
    return a.pos < b.pos;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<Point> points_inp(m);

    for(int i = 0; i < m; i++) {
        points_inp[i].idx = i + 1;
        cin >> points_inp[i].pos >> points_inp[i].weight;
    }

    sort(all(points_inp), cmp_weight);

    vector<Point> points(2 * n);
    for(int i = 0; i < 2 * n; i++)
        points[i] = points_inp[i];

    sort(all(points), cmp_pos);

    int sum = 0;
    for(auto point: points)
        sum += point.weight;

    cout << sum << endl;
    for(int i = 0; i < n; i++) 
        cout << points[i].idx << ' ' << points[2 * n - i - 1].idx << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
