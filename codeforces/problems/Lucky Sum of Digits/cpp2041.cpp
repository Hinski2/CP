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
const int inf = 1e6 + 7;
const int mak = 3e5 + 7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;

    ll bs = inf, bf = inf;
    for(ll f = 0; f < mak; f++) {
        if((n - 4*f) % 7 or n < 4*f) continue;
        ll s = (n - 4*f) / 7;


        if(f + s < bf + bs or (f + s == bs + bf and f < bf)) {
            bs = s;
            bf = f;
        }
    }

    if(bs == inf) {
        cout << -1 << endl;
    } else {
        for(int i = 0; i < bf; i++) cout << 4;
        for(int i = 0; i < bs; i++) cout << 7;
        cout << endl;
    }
}
