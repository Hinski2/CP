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

int solve(){
    pii a, b, f;
    cin >> a.fi >> a.se;
    cin >> b.fi >> b.se;
    cin >> f.fi >> f.se;

    int ans = 0;
    if(a == b) return 0;

    if(a.fi == b.fi && b.fi == f.fi && min(a.se, b.se) <= f.se && f.se <= max(a.se, b.se)) ans += 2;
    if(a.se == b.se && b.se == f.se && min(a.fi, b.fi) <= f.fi && f.fi <= max(a.fi, b.fi)) ans += 2;
    ans += abs(a.fi - b.fi) + abs(a.se - b.se);

    return ans;
}
    

int main(){
    io; int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
