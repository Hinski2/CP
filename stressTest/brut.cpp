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
typedef __int128_t ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tree<int,null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;
//erase: oms.erase(oms.upper_bound(value))

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const ull mak = 1ll * 1e9 * 1e9;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll n, m; cin >> n >> m;
    ll arr[n] = {0};

    for(int i = 0; i < n; i++)
        cin >> arr[i]; 
    while(m--){
        char c; cin >> c;
        if(c == 'Q'){
            int a, b; cin >> a >> b;
            ll suma = 0;
            for(int i = a; i <= b; i++)
                suma += arr[i];
            cout << suma << endl;
        }
        else{
            int n, x; cin >> n >> x;
            arr[n] = x;
        }
    }
}