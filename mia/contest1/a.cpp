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
const int mak = 105;
 
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
 
ll solve(){
    int n, m;
    ll matrix[205][205];
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> matrix[i][j];
 
    vector<ll> s1(n + m + 10), s2(n + m + 10);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            s1[i + j] += matrix[i][j];
            s2[i + m - j] += matrix[i][j];
        }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            ans = max(ans, s1[i + j] + s2[i + m - j] - matrix[i][j]);
 
    return ans;
}
 
int main(){
    get_input();
    int t;
    cin >> t;
 
    while(t--)
        cout << solve() << endl;
}