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

ll no_icecream, n;
void get_input(){
    cin >> n >> no_icecream;
}
int main(){
    get_input();
    int sad = 0;
    for(ll i = 0, x; i < n; i++){
        char c; cin >> c >> x;
        if(c == '+') no_icecream += x;
        else if(c == '-' && x <= no_icecream) no_icecream -= x;
        else sad++;
    }

    printf("%lld %lld\n", no_icecream, sad);
}
