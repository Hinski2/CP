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

template<typename T> unsigned arg_max(const vector<T> &v){
    T maxi = v[0];
    unsigned pos = 0;
    for(unsigned i = 1; i <= v.size(); i++)
        if(v[i] > maxi){
            maxi = v[i];
            pos = i;
        }
    return pos;
}

template<typename T> unsigned arg_min(const vector<T> &v){
    T mini = v[0];
    unsigned pos = 0;
    for(unsigned i = 1; i <= v.size(); i++)
        if(v[i] < mini){
            mini = v[i];
            pos = i;
        }
    return pos;
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

bool cmp(const pii &a, const pii &b) {
    if(a.se != b.se) return a.se < b.se;
    return a.fi < b.fi;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pii> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].fi, v[i].fi--;
    for(int i = 0; i < n; i++) cin >> v[i].se, v[i].se--;

    vector<int> inv(n);
    for(int i = 0; i < n; i++)
        inv[v[i].se] = i;

    vector<int> pos_out(n);
    for(int i = 0; i < n; i++) {
        pos_out[i] = inv[v[i].fi];
    }

    int maxi = -1, ans = 0;
    for(auto u: pos_out) {
        if(u > maxi) maxi = u;
        else ans++;
    }

    cout << ans << endl;
}
