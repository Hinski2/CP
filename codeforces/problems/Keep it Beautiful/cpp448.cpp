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
    int n, last = -1, fi = 0;
    cin >> n;

    int stop_grow = inf;
    for(int i = 0, x; i < n; i++){
        cin >> x;

        if(last == -1){
            fi = x;
            last = x;
            cout << '1';
        }

        else if(x >= last && x <= stop_grow){
            last = x;
            cout << '1';
        }
        else if(x <= last && stop_grow == inf && x <= fi){
            last = x;
            cout << '1';
            stop_grow = fi;
        }
        else if(stop_grow != inf && x <= stop_grow && x >= last){
            last = x;
            cout << '1';
        }
        else
            cout << '0';
    }

    cout << '\n';
}

int main(){
    get_input();
    while(t--)
        solve();
}
