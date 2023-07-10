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

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

int n, k;
ordered_set oset;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) oset.insert(i);

    int no = n, pos = 0;
    while(no-- != 0){
        pos = (pos + k) % (no + 1);
        
        int ans = *oset.find_by_order(pos);
        cout << ans << ' ';
        oset.erase(ans);
    }
}
