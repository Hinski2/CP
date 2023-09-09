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

int n, t;
vector<vector<ll>> v(3), sum(3);
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    v[1].resize(n + 1);
    v[2].resize(n + 1);
    sum[1].resize(n + 1);
    sum[2].resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> v[1][i];
        v[2][i] = v[1][i];
    }

    cin >> t;
}
int main(){
    get_input();
    sort(all(v[2]));

    for(int i = 1; i <= n; i++){
        sum[1][i] = sum[1][i - 1] + v[1][i];
        sum[2][i] = sum[2][i - 1] + v[2][i];
    }

    while(t--){
        int l, r, type;
        cin >> type >> l >> r;
        cout << sum[type][r] - sum[type][l - 1] << endl;
    }
}
