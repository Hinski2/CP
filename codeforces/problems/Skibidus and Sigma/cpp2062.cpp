#include <bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream& os, const pair<T, T>& v){
    os << v.first << ' ' << v.second << endl;
    return os;
}

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
#define int ll

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

struct S{
    int fi, se, sum;
};

int n, m;
bool cmp(const S& a, const S& b) {
    if(a.sum != b.sum)
        return a.sum > b.sum;
    return a.se > b.se;
}

int solve() {
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(auto &u: v)
        cin >> u;
    
    vector<S> ord(n); // sum, i
    for(int i = 0; i < n; i++) {
        ord[i].se = i;
        for(int j = 0; j < m; j++)
            ord[i].fi += (m - j) * v[i][j], ord[i].sum += v[i][j];
    }

    sort(all(ord), cmp);
    vector<int> ans;
    for(auto u: ord) {
        ans.insert(ans.end(), all(v[u.se]));
    }

    int sum = 0;
    for(int i = 0, mult = n * m; i < n * m; i++, mult--) {
        sum += ans[i] * mult;
    }
    return sum;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
