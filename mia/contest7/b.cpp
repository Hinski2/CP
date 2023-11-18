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

const int mod = 998'244'353;
const int inf = 1e9 + 7;
const int mak = 5007;

ll a, b, c;
ll fact[mak], newton[mak][mak];

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
}

ll solve(ll x, ll y){
    ll ans = 0;
    for(int i = 0; i <= min(x, y); i++){
        ll sum = fact[i];
        sum *= newton[x][i], sum %= mod;
        sum *= newton[y][i], sum %= mod;

        ans += sum; ans %= mod;
    }

    return ans;
}

int main(){
    get_input();
    fact[0] = 1;
    for(int i = 1; i < mak; i++)
        fact[i] = fact[i - 1] * i % mod;
    
    newton[0][0] = 1;
    for(int i = 1; i < mak; i++){
        newton[i][0] = 1;
        for(int j = 1; j <= i; j++)
            newton[i][j] = (newton[i - 1][j - 1] + newton[i - 1][j]) % mod;
    }

    ll ans = 1;
    ans *= solve(a, b), ans %= mod;
    ans *= solve(b, c), ans %= mod;
    ans *= solve(c, a), ans %= mod;

    cout << ans << endl;
}
