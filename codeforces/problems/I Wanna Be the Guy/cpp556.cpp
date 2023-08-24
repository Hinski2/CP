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

int n;
vector<bool> v;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin >> n;
    v.resize(n + 1);

    cin >> m;
    for(int i = 0, x; i < m; i++){
        cin >> x;
        v[x] = true;
    }
    cin >> m;
    for(int i = 0, x; i < m; i++){
        cin >> x;
        v[x] = true;
    }
}

bool solve(){
    for(int i = 1; i <= n; i++)
        if(!v[i]) return false;
    return true;
}

int main(){
    get_input();
    cout << (solve() ? "I become the guy." : "Oh, my keyboard!") << endl;
}
