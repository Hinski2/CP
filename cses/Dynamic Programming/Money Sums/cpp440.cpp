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

int n;
vector<int> numb;
bitset<mak> bis;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    numb.resize(n);
    for(int i = 0; i < n; i++)
        cin >> numb[i];
    
    bis[0] = 1; 
    for(auto u: numb)
        bis |= (bis << u);

    int cnt = 0;
    for(int i = 1;  i < mak; i++)
        if(bis[i]) cnt++;

    cout << cnt << '\n';
    for(int i = 1; i < mak; i++)
        if(bis[i]) cout << i << ' ';
    cout << endl;
}
