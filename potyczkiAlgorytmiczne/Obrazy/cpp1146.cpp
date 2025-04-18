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

ll n;
vector<ll> obrazy;

ll oblicz(ll x, ll y){
    if(x == 0 || y == 0) return 0;
    for(int i = n - 1; i >= 0; i--){
        ll a = x / obrazy[i];
        ll b = y / obrazy[i];

        if(a && b){
            ll ans = a * b;
            ans += oblicz(x - a * obrazy[i], b * obrazy[i]);
            ans += oblicz(x, y - b * obrazy[i]);
            return ans;
        }
    }
    return 0;
}

int main(){
    io; int h, w; cin >> h >> w >> n;
    obrazy.resize(n); cin >> obrazy;
    if(h % obrazy[0] || w % obrazy[0])
        cout << -1 << endl;
    else
        cout << oblicz(h, w) << endl;

}

