#include <bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v){
    for(const auto &u: v){
        os << u << ' ';
    }
    return os;
}

template<typename T> istream& operator>>(istream& is, pair<T, T>& v){
    is >> v.first >> v.second;
    return is;
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
#define int ll

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

int dist(pair<int, int> &a, pair<int, int> &b) {
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}

int solve() {
    int n, k, a, b; cin >> n >> k >> a >> b; a--, b--;
    vector<pair<int, int>> city(n); cin >> city;

    int cost_to_nearet_majour = inf * inf;
    for(int i = 0; i < k; i++)
        cost_to_nearet_majour = min(cost_to_nearet_majour, dist(city[a], city[i]));

    int cost_from_nearest_majour = inf * inf;
    for(int i = 0; i < k; i++)
        cost_from_nearest_majour = min(cost_from_nearest_majour, dist(city[b], city[i]));

    int ans = dist(city[a], city[b]);
    return min(ans, cost_to_nearet_majour + cost_from_nearest_majour);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cout << solve() << endl;
    }
}
