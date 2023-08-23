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

int solve(){
    int last = 0, no, n;
    cin >> n;

    vector<int>a_max(2 * n + 1), b_max(2 * n + 1);
    for(int i = 0, x; i < n; i++){
        cin >> x;

        if(last == x) no++;
        else no = 1;

        a_max[x] = max(a_max[x], no);
        last = x;
    }

    last = 0;
    for(int i = 0, x; i < n; i++){
        cin >> x;

        if(last == x) no++;
        else no = 1;

        b_max[x] = max(b_max[x], no);
        last = x;
    }

    int ans = 0;
    for(int i = 1; i <= 2 * n; i++)
        ans = max(ans, a_max[i] + b_max[i]);

    return ans;
}
int main(){
    get_input();
    while(t--)
        cout << solve() << endl;
}
