#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

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

bool solve(){
    int n;
    cin >> n;

    ll sum, diff = 0;
    vector<ll> pre(n), check(n + 1, 0);
    for(ll i = 1; i < n; i++)
        cin >> pre[i];

    for(ll i = 1; i < n; i++){
        if(pre[i] - pre[i - 1] <= n && check[pre[i] - pre[i - 1]] == 0)
            check[pre[i] - pre[i - 1]] = 1;
        else if(diff)
            return 0;
        else
            diff = pre[i] - pre[i - 1];
    }

    ll no_missing = 0, sum_missing = 0;
    for(ll i = 1; i <= n; i++){
        if(!check[i]){
            no_missing++;
            sum_missing += i;
        }
    }

    if(no_missing == 2 && diff == sum_missing) return 1;
    if(no_missing == 1) return 1;
    return 0;
}

int main(){
    get_input();
    while(t--)
        cout << (solve() ? "YES\n" : "NO\n");
}
