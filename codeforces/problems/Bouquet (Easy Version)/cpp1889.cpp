
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
#define yn (solve() ? YES : NO)
#define int ll

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

int solve(){
    int n, m; cin >> n >> m;
    vector<int> v(n); cin >> v;
    map<int, int> mapa;
    for(auto u: v) mapa[u]++;

    int ans = 0;
    for(auto [i, amm]: mapa){
        int amm2 = mapa.count(i + 1) ? mapa[i + 1] : 0;

        vector<int> v;
        for(int j = 0; j < amm; j++) v.pb(i);
        for(int j = 0; j < amm2; j++) v.pb(i + 1);

        int l = 0, sum = 0;
        for(int r = 0; r < v.size(); r++){
            sum += v[r];
            while(sum > m){
                sum -= v[l++];
            }

            ans = max(ans, sum);
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

