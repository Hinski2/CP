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
const int base = 1ll << 20;

int n;
string s;
int o[base * 2], c[base * 2], ans[base * 2];

struct S {
    int open, close, ans;
    S(int open = 0, int close = 0, int ans = 0) : open(open), close(close), ans(ans) {}

    friend S Merge(S l, S r) {
        int x = min(l.open, r.close);
        return S(l.open + r.open - x, l.close + r.close - x, l.ans + r.ans + 2 * x);
    }
};

struct Solver {

    Solver() {
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') o[i + base] = 1;
            else c[i + base] = 1;
        }

        for(int i = base - 1; i; i--) {
            int x = min(o[i * 2], c[i * 2 + 1]);
            ans[i] = ans[i * 2] + ans[i * 2 + 1] + 2 * x;
            o[i] = o[i * 2] + o[i * 2 + 1] - x;
            c[i] = c[i * 2] + c[i * 2 + 1] - x;
        }
    }    

    int solve(int l, int r) {
        l = l + base, r = r + base;

        S l_sum(o[l], c[l], ans[l]), r_sum(o[r], c[r], ans[r]);
        if(l == r) {
            return l_sum.ans;
        }

        for(; l / 2 != r / 2; l /= 2, r /= 2) {
            if(l % 2 == 0) l_sum = Merge(l_sum, S(o[l + 1], c[l + 1], ans[l + 1]));
            if(r % 2 == 1) r_sum = Merge(S(o[r - 1], c[r - 1], ans[r - 1]), r_sum);
        }

        return Merge(l_sum, r_sum).ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();

    Solver solver;

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << solver.solve(l - 1, r - 1) << endl;
    }
}
