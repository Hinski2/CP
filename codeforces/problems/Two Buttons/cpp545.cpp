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
const int mak = 2e4 + 10;

int n, target;
vector<int> ans(mak);

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> target;
}

void solve(){
    queue<pii> q;
    q.push({n, 0});

    while(!q.empty()){
        int u = q.front().fi;
        int op = q.front().se;
        q.pop();

        if(ans[u]) continue;
        ans[u] = op;
        
        if(u < target) q.push({u * 2, op + 1});
        if(u > 1) q.push({u - 1, op + 1});
    }
}

int main(){
    get_input();
    solve();
    cout << ans[target] << endl;
}
