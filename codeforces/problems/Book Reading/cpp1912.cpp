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

template<typename T> bool contains(const vector<T> &v, const T &val){
    for(auto u: v){
        if(u == val) return true;
    }

    return false;
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
    vector<int> cycle = {0};
    for(int i = m;!contains(cycle, i % 10); i += m){
        cycle.push_back(i % 10);
    }

    n = n / m;
    int no = n / cycle.size();
    int ans = no * sum(cycle);
    n -= no * cycle.size();
    for(int i = 0; i <= n; i++)
        ans += cycle[i];

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}

