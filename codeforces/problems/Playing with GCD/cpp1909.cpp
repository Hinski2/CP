
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

template<typename T> T min(const vector<T> &v){
    T m = v[0];
    for(auto u: v) m = min(m, u);
    return m;
}

template<typename T> T max(const vector<T> &v){
    T m = v[0];
    for(auto u: v) m = max(m, u);
    return m;
}

template<typename T> T gcd(const vector<T> &v){
    T g = v[0];
    for(auto u: v) g = __gcd(g, u);
    return g;
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

int lcm(int a, int b){
    int g = __gcd(a, b);
    return a / g * b;
}

int solve(){
    int n; cin >> n;
    vector<int> v(n + 2, 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    vector<int> b(n + 2, 1);
    for(int i = 1; i <= n + 1; i++)
        b[i] = lcm(v[i], v[i - 1]);

    for(int i = 1; i <= n; i++)
        if(__gcd(b[i], b[i + 1]) != v[i]) return 0;
    
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << yn << endl;
}

