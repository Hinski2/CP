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

vector<ll> cost, ans;
vector<vector<int>> G;

void policz(int v){
    ans[v] = 0;
    for(auto u: G[v]){
        if(ans[u] == inf) policz(u);
        ans[v] += ans[u];
    }

    ans[v] = min(ans[v], cost[v]);
}

void solve(){
    int n, k;
    cin >> n >> k;

    cost.clear();
    cost.resize(n + 1);

    ans.clear();
    ans.resize(n + 1, inf);

    G.clear();
    G.resize(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> cost[i];
    for(int i = 1, x; i <= k; i++){
        cin >> x;
        cost[x] = ans[x] = 0;
    }

    for(int i = 1, no; i <= n; i++){
        cin >> no;
        if(!no) ans[i] = cost[i];
        else
            for(int j = 1, v; j <= no; j++){
                cin >> v;
                G[i].pb(v);
            }
    }

    for(int i = 1; i <= n; i++)
        if(ans[i] == inf) policz(i);

    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
        
int main(){
    get_input();
    while(t--)
        solve();
}
