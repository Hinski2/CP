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

int t;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

ll solve(){
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(2, inf));
    for(int i = 0, m; i < n; i++){
        cin >> m;
        for(int j = 0, x; j < m; j++){
            cin >> x;
            if(x <= v[i][0]){
                v[i][1] = v[i][0];
                v[i][0] = x;
            }
            else if(x < v[i][1]){
                v[i][1] = x;
            }
        }
    }

    int where, smallest = inf;
    for(int i = 0; i < n; i++){
        if(v[i][1] < smallest){
            smallest = v[i][1];
            where = i;
        }
    }

    for(int i = 0; i < n; i++)
        if(i != where)
            v[where].pb(v[i][0]);

    sort(all(v[where]));
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i == where) ans += v[i][0];
        else ans += v[i][1];
    }

    return ans;
}

int main(){
    get_input();
    while(t--)
        cout << solve() << endl;
}
