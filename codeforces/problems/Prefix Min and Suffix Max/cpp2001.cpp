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

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1
#define yn (solve() ? "YES" : "NO")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

void solve() {
    int n; cin >> n;
    vector<int> v(n); cin >> v;
    vector<int> pref(n), suf(n); // min, max

    pref[0] = v[0], suf[n - 1] = v[n - 1];
    for(int i = 1; i < n; i++)
        pref[i] = min(pref[i - 1], v[i]);
    for(int i = n - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1], v[i]);


    vector<int> ans(n, 1);
    for(int i = 1; i <= n - 2; i++) {
        if(v[i] < pref[i - 1] or v[i] > suf[i + 1]) ans[i] = 1;
        else ans[i] = 0;
    }

    for(int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
