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

int main(){
    io; int n; cin >> n;
    vector<int> v(n); cin >> v;

    ll ans = 0;
    for(auto &u: v){
        if(u < 0) ans += abs(-1 - u), u = -1;
        if(u > 0) ans += abs(1 - u), u = 1;
    }

    int minus = 0, plus = 0, zero = 0;
    for(auto u: v){
        if(u == -1) minus++;
        if(u == 1) plus++;
        if(u == 0) zero++;
    }

    if((minus & 1) && zero) ans += 1, zero--;
    else if((minus & 1) && !zero) ans += 2;
    ans += zero;

    cout << ans << endl;
}
