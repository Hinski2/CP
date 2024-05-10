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


ll sprawdz(vector<ll> &v, vector<ll> &ans){
    ll s = 0;
    for(int i = 0; i < v.size(); i++)
        s += abs(v[i] - ans[i]);
    return s;
}

void solve(){
    ll n; cin >> n;
    vector<ll> v(n); cin >> v;
    vector<ll> ans1 = v, ans2 = v;
    for(int i = 0; i < n; i += 2)
        ans1[i] = 1;
    for(int i = 1; i < n; i += 2)
        ans2[i] = 1;
    
    if(sprawdz(v, ans1) < sprawdz(v, ans2))
        cout << ans1 << endl;
    else
        cout << ans2 << endl;
}

int main(){
    io; int t; cin >> t;
    while(t--)
        solve();
}
