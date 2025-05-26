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

template<typename T> T max(const vector<T> &v, int l, int r){
    T maxi = v[l];
    for(int i = l; i <= r; i++)
        maxi = max(maxi, v[i]);

    return maxi;
}

template<typename T> T min(const vector<T> &v, int l, int r){
    T mini = v[l];
    for(int i = l; i <= r; i++) 
        mini = min(mini, v[i]);

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

int solve() {
    int n; cin >> n;
    vector<int> v(n); cin >> v;
    sort(all(v));

    int ans = inf;
    for(int i = 0; i < n; i++) {
        if((min(v, i, n - 1) + max(v, i, n - 1)) % 2 == 0)
            ans = min(ans, i);
    }

    for(int i = n - 1; i > 0; i--) {
        if((min(v, 0, i) + max(v, 0, i)) % 2 == 0)
            ans = min(ans, n - 1 - i);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
