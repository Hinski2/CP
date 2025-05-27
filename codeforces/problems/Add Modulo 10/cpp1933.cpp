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
#define yn (solve() ? "Yes" : "No")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

struct Numb {
    int base;
    int rotate;

    void make_rotate(int x = 2) {
        for(int i = 0; i < x; i++) {
            base += rotate;
            rotate = base % 10;
        }
    }

    void get_rotate(int x) {
        for(int i = 0; i < 10 and rotate != x; i++) {
            base += rotate;
            rotate = base % 10;
        }
    }
};

bool solve() {
    int n; cin >> n;
    vector<Numb> v(n);
    for(auto &u: v) {
        int n; cin >> n;

        u.rotate = n % 10;
        u.base = n - n % 10;

        u.make_rotate();
    }

    for(auto &u: v) {
        u.get_rotate(v.front().rotate);

        if(u.rotate != v.front().rotate) {
            return 0;
        }
    }

    if(v.front().rotate == 0) {
        for(auto u: v) {
            if(u.base != v.front().base) return 0;
        }
        return 1;
    } else {
        for(auto u: v) {
            if(u.base % 20 != v.front().base % 20) return 0;
        }
        return 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << yn << endl;
}
