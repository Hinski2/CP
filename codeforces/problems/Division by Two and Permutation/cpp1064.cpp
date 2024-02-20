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

bool solve(){
    int n; cin >> n;
    vector<int> v(n); cin >> v;

    vector<vector<int>> occ(n + 1);
    for(int i = 0; i < n; i++){
        while(v[i]){
            if(v[i] <= n) occ[v[i]].pb(i);
            v[i] /= 2;
        }
    }

    vector<pii> order(n + 1);
    for(int i = 1; i <= n; i++)
        order[i] = {occ[i].size(), i};
    sort(all(order));
    vector<bool> taken(n + 1);
    for(int i = 1; i <= n; i++){
        bool chosen = false;
        for(auto w: occ[order[i].se]){
            if(!taken[w]){ 
                chosen = true, taken[w] = 1;
                break;
            }
        }
        if(!chosen) return 0;
    }

    return 1;
}

int main(){
    io; int t; cin >> t;
    while(t--)
        cout << yn << endl;
}
