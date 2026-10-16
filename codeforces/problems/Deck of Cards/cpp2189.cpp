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

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

string solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int bottom = count(all(s), '0');
    int top = count(all(s), '1');
    int idk = count(all(s), '2');
    if(n == k)
        return string(n, '-');


    string l(n, '+'), r(n, '+');
    for(int i = 0; i < bottom; i++)
        l[i] = '-';
    for(int i = 0; i < idk; i++)
        l[i + bottom] = '?';

    for(int i = 0; i < top; i++)
        r[n - 1 - i] = '-';
    for(int i = 0; i < idk; i++)
        r[n - top - i - 1] = '?';
    
    string ans(n, '+');
    for(int i = 0; i < n; i++) {
        if(l[i] == '-' or r[i] == '-') ans[i] = '-';
        else if(l[i] == '?' or r[i] == '?') ans[i] = '?';
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
