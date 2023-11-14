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
ll a, b, x, y, n;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

ll solve(){
    ll ile_z_a = min(a - x, n);
    ll ile_z_b = min(b - y, n);

    if(a - ile_z_a < b - ile_z_b){
        a -= ile_z_a;
        n -= ile_z_a;

        if(n)
            b -= min(ile_z_b, n);
    }
    else{
        b -= ile_z_b;
        n -= ile_z_b;

        if(n)
            a -= min(ile_z_a, n);
    }

    return a * b;
}
int main(){
    get_input();

    while(t--){
        cin >> a >> b >> x >> y >> n;
        cout << solve() << endl;
    }
}
