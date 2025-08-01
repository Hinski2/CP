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

int c;
bool cmp(const int a, const int b) {
    if(a <= c and b <= c)
        return a > b;
    else if(a <= c) return true;
    else if(b <= c) return false;
    return a > b;
}

int solve() {
    int n; cin >> n >> c;
    vector<int> v(n); cin >> v;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        sort(all(v), cmp);
        if(v[0] > c) {
            ans++;
        }

        swap(v.front(), v.back());
        v.pop_back();

        for(auto &u: v) {
            u = min(u * 2, c * 2);
        }
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
