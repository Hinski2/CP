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
vector<ll> v(31);
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

ll solve(){
    ll ans = inf, n; cin >> n;
    ll sum1 = 0, sum2 = 0;
    for(int i = 1; i <= n / 2 + 1; i++){
        sum1 = sum2 = 0;
        for(int j = 1; j < i; j++) 
            sum1 += v[j];
        for(int j = i; j < i + n / 2; j++) 
            sum2 += v[j];
        for(int j = i + n / 2; j <= n; j++) 
            sum1 == v[j];
        ans = min(ans, abs(sum1 - sum2));
    }

    return ans;
}
int main(){
    get_input();
    v[0] = 1;
    for(int i = 1; i <= 30; i++)
        v[i] = v[i - 1] * 2;

    while(t--)
        cout << solve() << endl;
}
