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
#define int ll

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

int solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);  cin >> a >> b;

    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] != -1 and b[i] != -1) {
            if(ans != -1 and ans != a[i] + b[i]) return 0;
            ans = a[i] + b[i];
        }
    }

    if(ans == -1) {
        if(a[0] == -1) swap(a, b); //vals in a

        int mini = min(a);
        int maxi = max(a);

        int x = maxi - mini;
        return max(0ll, k - x + 1);
    } else {
        for(int i = 0; i < n; i++) {
            if(a[i] == -1 and b[i] == -1) {
                if(2*k < ans) return 0;
            } else if(a[i] == -1) {
                if(b[i] + k < ans or b[i] > ans) return 0;
            } else if(b[i] == -1) {
                if(a[i] + k < ans or a[i] > ans) return 0;
            }
        }

        return 1;
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cout << solve() << endl;
    }
}
