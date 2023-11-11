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

const ll mod = 1e9 + 7;
const ll inf = 1e9 + 7;
const ll mak = 2e5 + 7;

int n;
vector<int> v, ans(1e6 + 15);
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n);
    for(auto &u: v) cin >> u;
}


int main(){
    get_input();
    ans[0] = 1;
    for(auto u: v){
        vector<int> div;
        for(int i = 1; i * i <= u; i++){
            if(u % i) continue;

            div.pb(i);
            if(i != u / i) div.pb(u / i);
        }
        sort(all(div), greater<int>());
        for(auto d: div){
            ans[d] += ans[d - 1];
            ans[d] %= mod;
        }
    }

    ll sum = 0;
    for(int i = 1; i <= 1e6; i++){
        sum += ans[i];
        sum %= mod;
    }
    cout << sum << endl;
}
