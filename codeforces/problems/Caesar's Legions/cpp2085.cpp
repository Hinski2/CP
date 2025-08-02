#include <bits/stdc++.h>
using namespace std;

// geometry
template<typename T>
ostream& operator<<(ostream& os, const pair<T, T>& p) {
    os << p.first << ' ' << p.second << '\n';
    return os;
}

template<typename T> 
istream& operator>>(istream& is, pair<T, T>& p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T>
pair<T, T> operator + (const T& a, const T& b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

template<typename T>
pair<T, T> operator - (const T& a, const T& b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

template<typename T>
T operator * (const T& a, const T& b) {
    return a.first * b.second - a.second * b.first;
}

template<typename T>
T cross_product(const T& a, const T& b) {
    return a * b;
}

template<typename T>
T cross_product(const T& a, const T& b, const T& c) {
    return (b - a) * (c - a);
}

// vector
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const auto &u: v) {
        os << u << ' ';
    }
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v) {
    for(auto& u : v) {
        is >> u;
    }
    return is;
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

const int mod = 1e8;
const int inf = 1e9 + 7;
const int mak = 105;

int max_footman, max_horseman, ans[mak][mak][2]; // 0 - footman, 1 - horseman #last
void solve(int footman, int horseman, int last) {
    if(ans[footman][horseman][last] != -1) return;

    if(last == 0) { // now horseman
        if(footman == 0) ans[footman][horseman][last] = horseman <= max_horseman;
        else {
            ans[footman][horseman][last] = 0;
            for(int i = 1; i <= max_horseman and horseman - i >= 0; i++) {
                solve(footman, horseman - i, last ^ 1);
                ans[footman][horseman][last] += ans[footman][horseman - i][last ^ 1];
                ans[footman][horseman][last] %= mod;
            }
        }
    } else { // now fotman
        if(horseman == 0) ans[footman][horseman][last] = footman <= max_footman;
        else {
            ans[footman][horseman][last] = 0;
            for(int i = 1; i <= max_footman and footman - i >= 0; i++) {
                solve(footman - i, horseman, last ^ 1);
                ans[footman][horseman][last] += ans[footman - i][horseman][last ^ 1];
                ans[footman][horseman][last] %= mod;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int footman, horseman; cin >> footman >> horseman >> max_footman >> max_horseman;
    for(int i = 0; i < mak; i++)
        for(int j = 0; j < mak; j++)
            ans[i][j][0] = ans[i][j][1] = -1;

    solve(footman, horseman, 0);
    solve(footman, horseman, 1);

    cout << (ans[footman][horseman][0] + ans[footman][horseman][1]) % mod << endl;
}
