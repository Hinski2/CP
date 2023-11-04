#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1

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

int t;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

ll Add(ll T){
    if(T == 0) return 0;
    if(T > 32) return 1ll << 32;
    return 1ll << T;
}

ll solve(){
    ll n; cin >> n;
    vector<ll> v(n);
    for(auto &u: v) cin >> u;

    ll maxi = 0;
    for(int i = 1; i < n; i++){
        if(v[i - 1] > v[i]){
            maxi = max(maxi, v[i - 1] - v[i]);
            v[i] = v[i - 1];
        }
    }

    return (int)ceil(log2(maxi + 1));
}


int main(){
    get_input();
    while(t--)
        cout << solve() << endl;
}
