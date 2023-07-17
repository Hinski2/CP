#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back

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

void solve(){
    int n;
    vector<int> a, b;

    cin >> n;
    a.resize(n);
    b.resize(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++){
        int g = __gcd(a[i], b[i]);
        if(g){
            a[i] /= g;
            b[i] /= g;
        }

        a[i] %= 2;
        b[i] %= 2;
    }

    pii d = {0, 0};
    for(int i = 0; i < n; i++){
        if(!a[i] && !b[i]) continue;
        if(!d.fi && !d.se){
            d.fi = a[i];
            d.se = b[i];
        }

        if(a[i] != d.fi || b[i] != d.se){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    get_input();
    while(t--)
        solve();

}
