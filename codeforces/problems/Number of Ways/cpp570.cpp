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
const ll inf = 1e15;
const int mak = 2e5 + 7;

ll n, sum;
vector<ll> v;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    v.resize(n + 1);
    for(int i = 1, x; i <= n; i++){
        cin >> v[i];
        sum += v[i];
    }
}

ll solve(ll len){
    vector<ll> cnt(n + 1);
    cnt[n] = v[n];
    for(int i = n - 1; i > 0; i--)
        cnt[i] = cnt[i + 1] + v[i];

    for(int i = n; i > 0; i--)
        cnt[i] = cnt[i] == len;

    vector<ll> sums(n + 1);
    sums[n] = cnt[n];
    for(int i = n - 1; i > 0; i--)
        sums[i] = sums[i + 1] + cnt[i];

    ll ans = 0, pref = 0;
    for(int i = 1; i <= n - 2; i++){
        pref += v[i];
        if(pref == len) ans += sums[i + 2];
    }

    return ans;
}

int main(){
    get_input();
    if(sum % 3 != 0){
        cout << 0 << endl;
        exit(0);
    }

    cout << solve(sum / 3) << endl; 
}
