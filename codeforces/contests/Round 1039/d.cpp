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

int solve() {
    int n; cin >> n; 
    vector<int> v(n + 1); for(int i = 1; i <= n; i++) cin >> v[i];
    vector<int> dp(n + 1, 1);

    // len 1
    int ans = n; 

    // len 2
    for(int i = 2; i <= n; i++) {
        if(v[i - 1] > v[i]) {
            dp[i]++;
        }

        ans += dp[i];
    }

    // len > 2
    for(int len = 3; len <= n; len++) {
        for(int i = n; i - len >= 0; i--) {
            if(v[i - 2] < v[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else if(v[i - 1] > v[i]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = dp[i - 1];
            }

            ans += dp[i];
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
