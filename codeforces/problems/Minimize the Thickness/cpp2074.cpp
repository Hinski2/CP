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

template<typename T> T max(T a) {
    return a;
}

template<typename T, typename ... Ts> T max(const T& a, const Ts& ... ts) {
    return ( (a > ts ? a : ts), ...);
}

template<typename T> T min(T a) {
    return a;
}

template<typename T, typename ... Ts> T min(const T& a, const Ts& ... ts) {
    return ( (a < ts ? a : ts), ...);
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

int sovle() {
    int n; cin >> n;
    vector<int> v(n); cin >> v;

    auto check = [&](int sum) {
        int curr_sum = 0, len = 0, max_len = 0;

        for(int i = 0; i < n; i++) {
            curr_sum += v[i], len++;
            max_len = max(max_len, len);

            if(curr_sum > sum) return inf;
            else if(curr_sum == sum) curr_sum = 0, len = 0;
        }

        return curr_sum == 0 ? max_len : inf;
    };

    int sum = 0, ans = inf;
    for(int i = 0; i < n; i++) {
        sum += v[i];
        ans = min(check(sum), ans);
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << sovle() << endl;
}
