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


ll suma(vector<ll> &v){
    ll suma = 0;
    for(auto u: v) suma += u;
    return suma;
}
ll solve(){
    ll n, m, k, sum = 0;
    cin >> n >> m >> k;

    vector<vector<ll>> v(2);
    v[0].resize(n), v[1].resize(m);
    for(auto &u: v[0]) cin >> u;
    for(auto &u: v[1]) cin >> u;
    sort(all(v[0])), sort(all(v[1]));

    //1 ruch
    if(v[1].back() > v[0].front()) swap(v[1].back(), v[0].front());
    sort(all(v[0])), sort(all(v[1]));
    if(k == 1) return suma(v[0]);

    //2 ruch
    if(v[0].back() > v[1].front()) swap(v[0].back(), v[1].front());
    sort(all(v[0])), sort(all(v[1]));
    if(k == 2) return suma(v[0]);

    if(k % 2 && v[1].back() > v[0].front()) swap(v[1].back(), v[0].front());
    return suma(v[0]);
}


int main(){
    get_input();
    while(t--)
        cout << solve() << endl;
}
