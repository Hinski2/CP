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

ll n, x, y, ans;
ll ile_wciec;
string s;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x >> y;
    cin >> s;
    int occ = -1;
    for(int i = n - 1; i >= 0 && occ == -1; i--) if(s[i] == '0') occ = i;
    for(int i = 0; i < n - 2; i++) if(s[i] == '0' && s[i + 1] == '1' && i + 2 <= occ) ile_wciec++;
}

void zlicz_zero(){
    char last = '2';
    ll ile = 0;

    for(auto u: s){
        if(u == '0' && last != '0') ile++;
        last = u;
    }

    ans = ile * y;
}
int main(){
    get_input();
    zlicz_zero();
    ans = min(ans, ile_wciec * x + y);
    cout << ans << endl;
}
