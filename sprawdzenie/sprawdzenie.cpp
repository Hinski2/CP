#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
    for(const auto &u: v){
        os << u << ' ';
    }
    return os;
}
template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& u : v){
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
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define yn (solve() ? "YES" : "NO")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tree<int,null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;
//erase: oms.erase(oms.upper_bound(value))

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

bool cmp(const pii a, const pii b){
    if(a.se != b.se) return a.se > b.se;
    return a.fi > b.fi;
}

int sprawdzenie(){
    int n; cin >> n;
    vector<int> v(n); cin >> v;

    map<int, int> mapa;
    for(auto u: v)
        mapa[u]++;

    vector<pii> w;
    for(auto u: mapa)
        w.pb({u.fi, u.se});
    sort(all(w), cmp);

    //TODO opczaj kolejność ma być od najwiekszego do najmneijszego
    
    int l = 0, r = w.size() - 1;
    while(l != r){
        if(w[l].se - w[r].se < 1){ 
            w[r].se -= w[l].se - 1;
            l++;
        }
        else{
            w[l].se -= w[r].se;
            r--;
        }
    }

    return l + 1;
}

int main(){
    io;
    cout << sprawdzenie() << endl;
}
