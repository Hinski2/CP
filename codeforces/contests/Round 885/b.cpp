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

void solve(){
    int n, c;
    vector<vector<int>> kolor;

    cin >> n >> c;
    kolor.resize(c + 1);

    for(int i = 1; i <= c; i++)
        kolor[i].pb(0);

    for(int i = 1, deska; i <= n; i++){
        cin >> deska;
        kolor[deska].pb(i);
    }

    for(int i = 1; i <= c; i++)
        kolor[i].pb(n + 1);

    int now1 = 0, now2 = 0, ans = inf;
    for(int i = 1; i <= c; i++){
        now1 = now2 = 0;
        for(int j = 1; j < kolor[i].size(); j++){
            if(now1 < kolor[i][j] - kolor[i][j - 1]){
                now2 = now1;
                now1 = kolor[i][j] - kolor[i][j - 1];
            }
            else if(now2 < kolor[i][j] - kolor[i][j - 1])
                now2 = kolor[i][j] - kolor[i][j - 1];
        }

        ans = min(ans, max((now1 + 1) / 2, now2));
    }

    cout << ans - 1 << '\n';
}

int main(){
    get_input();
    while(t--)
        solve();
}
