#include <bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v){
    for(const auto &u: v){
        os << u << ' ';
    }
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v){
    for(auto& u : v){
        is >> u;
    }
    return is;
}

template<typename T> long long sum(const vector<T> &v){
    long long s = 0;
    for(auto u: v) s += u;
    return s;
}

template<typename T> T max(const vector<T> &v){
    T maxi = v[0];
    for(auto u: v) maxi = max(maxi, u);
    return maxi;
}

template<typename T> T min(const vector<T> &v){
    T mini = v[0];
    for(auto u: v) mini = min(mini, u);
    return mini;
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
    vector<int> in1(n), in2(n); cin >> in1 >> in2;

    vector<vector<int>> uni(n);
    for(int i = 0; i < n; i++) {
        uni[in1[i] - 1].push_back(in2[i]);
    }

    for(auto &u: uni){
        sort(all(u), greater<int>());
    }

    vector<int> ans(n);
    for(auto &u: uni) {
        int m = u.size();
        for(int i = 1; i < m; i++)
            u[i] += u[i - 1];

        for(int i = 0; i < m; i++) {
            ans[i] += u[m / (i + 1) * (i + 1) - 1];
        }
    }

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
