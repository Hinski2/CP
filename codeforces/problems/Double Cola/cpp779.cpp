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

vector<string> q;
int n;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    q.pb("Sheldon");
    q.pb("Leonard");
    q.pb("Penny");
    q.pb("Rajesh");
    q.pb("Howard");
}
int main(){
    get_input();

    int idx = 0;
    while(n > 5 * (1 << idx))
        n -= 5 * (1 << idx), idx++;
    
    n = ceil((n - 1) / (1 << idx));
    cout << q[n] << endl;
}
