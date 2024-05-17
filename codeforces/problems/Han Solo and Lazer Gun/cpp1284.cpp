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
pll m;

bool ok(pll a, pll b, pll c){
    ll x1 = b.fi - a.fi;
    ll y1 = b.se - a.se;
    ll x2 = c.fi - b.fi;
    ll y2 = c.se - b.se;

    return x1 * y2 - y1 * x2 == 0;
}

int main(){
    io; int n; cin >> n >> m.fi >> m.se;
    vector<pll> v(n);
    for(int i = 0, x, y; i < n; i++)
        cin >> v[i].fi >> v[i].se;
    
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < v.size(); j++)
            if(ok(v[i], v[j], m)){
                if(j == v.size() - 1) v.pop_back();
                else{
                    swap(v[j], v[v.size() - 1]);
                    v.pop_back();
                    j--;
                }
            }
    cout << v.size() << endl;
}
