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

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> v(n); cin >> v;
    vector<ll> sum(2), numb(2);

    for(auto u: v)
        sum[u & 1] += u, numb[u & 1]++;
    
    for(int i = 0; i < q; i++){
        ll a, b; cin >> a >> b;
        if(a == 0){
            if(b & 1){
                sum[0] += b * numb[0];
                sum[1] += sum[0];
                sum[0] = 0;
                numb[1] += numb[0];
                numb[0] = 0;
            }
            else
                sum[0] += b * numb[0];
        }
        else{
            if(b & 1){
                sum[1] += b * numb[1];
                sum[0] += sum[1];
                sum[1] = 0;
                numb[0] += numb[1];
                numb[1] = 0;
            }
            else
                sum[1] += b * numb[1];
        }

        cout << sum[0] + sum[1] << endl;
    }

}

int main(){
    io; int t; cin >> t;
    while(t--)
        solve();
}
