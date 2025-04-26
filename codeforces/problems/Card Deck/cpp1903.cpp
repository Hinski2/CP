
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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

void solve(){
    int n; cin >> n;
    vector<int> v(n); cin >> v;

    vector<int> ans, to_add;
    for(auto u: v){
        if(to_add.empty() or to_add.front() > u){
            to_add.pb(u);
        } else {
            reverse(all(to_add));
            for(auto w: to_add){
                ans.pb(w);
            }
            to_add.clear();
            to_add.pb(u);
        }
    }

    reverse(all(to_add));
    for(auto w: to_add){
        ans.pb(w);
    }

    reverse(all(ans));
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}

