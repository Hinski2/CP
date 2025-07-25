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
const int mak = 1e3 + 7;

int n, m;
bool ban[mak][mak];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    vector<int> cand(n + 1, 1);
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        ban[a][b] = true;
        ban[b][a] = true;
        cand[a] = cand[b] = false;
    }

    int x = max_element(cand.begin() + 1, cand.end()) - cand.begin();
    
    vector<pii> ans;
    for(int i = 1; i <= n; i++) {
        if(i == x or ban[i][x]) continue;
        ans.pb({i, x});
    }

    for(int i = 1; i <= n; i++) {
        if(!ban[i][x]) continue;
        for(int j = 1; j <= n; j++) {
            if(j == x or ban[x][j] or ban[i][j]) continue;
            ans.pb({i, j});
            break;
        }
    }

    cout << ans.size() << endl;
    for(auto u: ans)
        cout << u.fi << ' ' << u.se << endl;
}
