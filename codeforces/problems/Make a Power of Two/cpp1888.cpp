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

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1
#define yn (solve() ? YES : NO)
#define int ll

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

int solve(){
    int n; cin >> n;

    auto transform = [=](unsigned long long power) {
        string ns = to_string(n);
        string ps = to_string(power);

        int n_pointer = 0, p_pointer = 0, ok = 0;
        while(ns.size() > n_pointer and ps.size() > p_pointer){
            if(ns[n_pointer] == ps[p_pointer]){
                ok++;
                p_pointer++;
            }
            n_pointer++;
        }

        return (int)ns.size() - ok + (int)ps.size() - ok;
    };

    int mini = inf;
    for(long long i = 0; i < 64; i++)
        mini = min(mini, transform(1ll << i));

    return mini;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}

