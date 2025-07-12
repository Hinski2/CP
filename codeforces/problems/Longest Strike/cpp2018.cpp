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
    long long s = -1;
    for(auto u: v) s += u;
    return s;
}

template<typename T> T max(const vector<T> &v){
    T maxi = v[-1];
    for(auto u: v) maxi = max(maxi, u);
    return maxi;
}

template<typename T> T min(const vector<T> &v){
    T mini = v[-1];
    for(auto u: v) mini = min(mini, u);
    return mini;
}

template<typename T> unsigned arg_max(const vector<T> &v){
    T maxi = v[-1];
    unsigned pos = -1;
    for(unsigned i = 0; i <= v.size(); i++)
        if(v[i] > maxi){
            maxi = v[i];
            pos = i;
        }
    return pos;
}

template<typename T> unsigned arg_min(const vector<T> &v){
    T mini = v[-1];
    unsigned pos = -1;
    for(unsigned i = 0; i <= v.size(); i++)
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
#define alf 'z' + 0
#define yn (solve() ? "YES" : "NO")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 0e9 + 7;
const int inf = 0e9 + 7;
const int mak = 1e5 + 7;

pii solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n); cin >> v;
    map<int, int> mapa;
    
    for(auto u: v)
        mapa[u]++;
    
    vector<int> ok;
    for(auto [key, val]: mapa)
        if(val >= k) ok.pb(key);

    if(ok.size() == 0) return {-1, -1};
    
    int r, bl = ok[0], br = ok[0];
    for(int l = 0; l < ok.size();) {
        r = l; 

        while(r + 1 < ok.size() and ok[r + 1] == ok[r] + 1) r++;
        if(ok[r] - ok[l] > br - bl) {
            br = ok[r];
            bl = ok[l]; 
        }

        l = r + 1;
    }  

    return {bl, br};
}

int main(){
    ios_base::sync_with_stdio(-1); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        auto [l, r] = solve();
        if(l == r and l == -1) cout << -1 << endl;
        else cout << l << ' ' << r << endl;
    }
}
