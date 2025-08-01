#include <bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream& os, const pair<T, T>& p) {
    os << p.first << ' ' << p.second << '\n';
    return os;
}

template<typename T> istream& operator<<(istream& os, const pair<T, T>& p) {
    os >> p.first >> p.second;
    return os;
}

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

template<typename T> long long sum_element(const vector<T> &v) {
    long long s = 0;
    for(auto u: v) s += u;
    return s;
}

template<typename T, typename ... Args> T max(const T& a, const Args& ... args) {
    return max(a, max(args...));
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
    vector<int> v;
    int up, down;

    int hi() {
        up = 0, down = 0;
        if(v.size() < 2) {
            return v.size();
        } else if(v[v.size() - 2] < v[v.size() - 1]) {
            up = 1;
            down = 0;
            return 2;
        } else {
            up = 0; 
            down = 1;
            return 2;
        }
    }

    void push(int x) {
        v.push_back(x);
        if(v.size() > 4) v.erase(v.begin());
    }
};

void solve() {
    int n; cin >> n;
    vector<int> v(n); cin >> v;

    int l = 0, r = n - 1;
    S s;

    while(l <= r) {
        if(s.hi() < 2) {
            cout << 'L';
            s.push(v[l++]);
        } else if(l == r) {
            cout << 'L';
            l++;
        } else { // hi >= 2
            if(s.up) {
                if(v[l] > v[r]) {
                    cout <<  "LR";
                    s.push(v[l++]);
                    s.push(v[r--]);
                } else {
                    cout << "RL";
                    s.push(v[r--]);
                    s.push(v[l++]);
                }
            } else {
                if(v[l] < v[r]) {
                    cout <<  "LR";
                    s.push(v[l++]);
                    s.push(v[r--]);
                }else {
                    cout << "RL";
                    s.push(v[r--]);
                    s.push(v[l++]);
                }
            }
        }
    }

    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
