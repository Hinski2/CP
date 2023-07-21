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

int solve(){
    int ans = 0; 
    string l, r;
    cin >> l >> r;

    while(l.size() != r.size())
        l = '0' + l;

    bool same = true;
    for(int i = 0; i < l.size() && same; i++){
        if(l[i] != r[i]){
            same = false;
            ans = 9 * (l.size() - i - 1);
            ans += abs(l[i] - '0' - (r[i] - '0'));
        }
    }

    return ans;
}  




int main(){
    get_input();
    while(t--)
        cout << solve() << '\n';
}
