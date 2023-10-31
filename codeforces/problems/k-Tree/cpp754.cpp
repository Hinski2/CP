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

ll n, k, d;
vector<ll>fact;
vector<vector<map<ll, ll>>> ustawienie;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> d;
}

void make_ustawienie(){
    ustawienie.resize(n + 1);
    ustawienie[0].resize(1);

    for(int kk = 1; kk <= k; kk++)
        for(int i = kk; i <= n; i++)
            for(int j = 0; j < ustawienie[i - kk].size(); j++){
                ustawienie[i].pb(ustawienie[i - kk][j]);
                ustawienie[i].back()[kk]++;
            }
}

void make_fact(){
    fact.resize(n + 1);

    fact[0] = 1;
    for(ll i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;
}

ll inv(ll x, ll pow = mod - 2){
    ll res = 1;
    
    while(pow){
        if(pow & 1) res = res * x % mod;
        x = x * x % mod;
        pow >>= 1;
    }

    return res;
}

ll solve(){
    ll ans = 0;
    for(auto u: ustawienie[n]){
        bool found = false;

        ll noNoumber = 0, subAns = 1;
        for(auto w: u){
            if(w.fi >= d) found = true;
            noNoumber += w.se;
        }

        if(!found) continue;
        subAns *= fact[noNoumber]; subAns %= mod;

        for(auto w: u){
            subAns *= inv(fact[w.se]);
            subAns %= mod;
        }

        ans += subAns;
        ans %= mod;
    }

    return ans;
}

int main(){
    get_input();
    make_ustawienie();
    make_fact();
    cout << solve() << endl;
}
