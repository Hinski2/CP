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

    cout << fixed << setprecision(7);
}

void solve(){
    double n, a, H;
    cin >> n >> a >> H;

    double p = a * H / 2;
    double ans = n * p;
    vector<ll> vec(n);

    for(int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());

    for(int i = 0; i < n - 1; i++){
        double h = vec[i] + H - vec[i + 1];
        if(h > 0 && h < H) 
            ans -= p * ((double)h / H) * ((double)h / H);
    }

    cout << ans << '\n';
} 

int main(){
    get_input();
    while(t--)
        solve();
}
