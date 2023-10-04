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

pii check(int x, int start){
    for(int i = start; i * i < x; i++)
        if(x % i == 0) return {x / i, i};
    return {0, 0};
}

void solve(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i != 0) continue;

        pii app = check(x / i, i + 1);
        if(app.fi == 0) continue;

        cout << "YES" << endl;
        cout << app.fi << ' ' << app.se << ' ' << i << endl;
        return;
    }
    cout << "NO" << endl;
}

int main(){
    get_input();

    int x;
    while(t-- && cin >> x)
        solve(x);
}
