#include <bits/stdc++.h>
#include <cctype>
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

int n;
string s[2];
constexpr pii moves[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool solve() {
    // get input
    cin >> n;
    cin >> s[0] >> s[1];
    vector<int> vis[2];
    vis[0].resize(n);
    vis[1].resize(n);

    // find ans

    queue<pii> to_add; to_add.push({1, 1});
    while(!to_add.empty()) {
        auto [x, y] = to_add.front(); to_add.pop();
        if(vis[x][y]) continue;
        vis[x][y] = true;

        if(x == 1 and y == n - 1) return 1;

        for(auto [mx, my]: moves) {
            mx += x; my += y;
            if(mx < 0 or mx >= 2) continue;
            if(my < 0 or my >= n) continue;

            if(s[mx][my] == '<') my--;
            else if(s[mx][my] == '>') my++;

            to_add.push({mx, my});
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cout << yn << endl;
    }
}
