
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
    int n, m, q; cin >> n >> m >> q;
    vector<int> t_pos(m); cin >> t_pos;
    sort(all(t_pos));

    while(q--){
        int d_pos; cin >> d_pos;

        if(d_pos < t_pos.front()){
            cout << t_pos.front() - 1 << endl;
        } else if (d_pos > t_pos.back()){
            cout << n - t_pos.back() << endl;
        } else {
            auto lo = lower_bound(t_pos.begin(), t_pos.end(), d_pos);
            auto up = upper_bound(t_pos.begin(), t_pos.end(), d_pos);

            if(*lo > d_pos) lo--;
            cout << (*up - *lo) / 2 << endl;
        }

   }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}

