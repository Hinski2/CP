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

int solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> pos_a;
    for(int i = 0; i < n; i++)
        if(s[i] == 'a') pos_a.pb(i);

    vector<int> sum_b(n), sum_c(n); 
    sum_b[0] = s[0] == 'b';
    sum_c[0] = s[0] == 'c';

    for(int i = 1; i < n; i++) {
        sum_b[i] = sum_b[i - 1] + (s[i] == 'b');
        sum_c[i] = sum_c[i - 1] + (s[i] == 'c');
    }

    int ans = inf;
    if(pos_a.size() >= 2 and sum_b[pos_a[1]] - sum_b[pos_a[0]] < 2 and sum_c[pos_a[1]] - sum_c[pos_a[0]] < 2) ans = pos_a[1] - pos_a[0] + 1;
    for(int i = 2; i < pos_a.size(); i++) {
        int l = pos_a[i - 1];
        int r = pos_a[i];
        if(sum_b[r] - sum_b[l] < 2 and sum_c[r] - sum_c[l] < 2) ans = min(ans, r - l + 1);

        l = pos_a[i - 2];
        r = pos_a[i];
        if(sum_b[r] - sum_b[l] <= 2 and sum_c[r] - sum_c[l] <= 2) ans = min(ans, r - l + 1);
    }

    return ans == inf ? -1 : ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
