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
    ll ans = 0, n, basic_cost; cin >> n >> basic_cost;
    vector<pii> v(n); //koszt, ile
    for(int i = 0; i < n; i++)
        cin >> v[i].se;
    for(int i = 0; i < n; i++)
        cin >> v[i].fi;

    sort(all(v));
    int idx = 0;
    queue<pii> ava;
    ava.push(v[idx++]);
    ans += basic_cost;

    while(ava.front().se){
        if(idx == n) return ans;
        if(ava.front().fi >= basic_cost){
            ans += 1LL * (n - idx) * basic_cost;
            return ans;
        }
        ava.push(v[idx++]), ans += ava.front().fi;
        ava.front().se--;
        if(!ava.front().se) ava.pop();
    }

    return ans;
} 
int main(){
    get_input();
    while(t--)
        cout << solve() << endl;
}
