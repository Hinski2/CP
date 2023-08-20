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

void solve(){
    ll n, biggest = -100, idx = 1;
    vector<ll> v;
    vector<pll> op;

    cin >> n;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(v[i] > biggest){
            biggest = v[i];
            idx = i;
        }
    }

    if(n == 1){
        cout << 0 << endl;
        return;
    }
    else if(biggest <= 0){
        for(int i = n - 1; i > 0; i--)
            op.pb({i, i + 1});
    }
    else{
        while(biggest < 20){
            op.pb({idx, idx});
            biggest *= 2;
        }

        while(v[2] < biggest){
            v[2] += biggest;
            op.pb({2, idx});
        }

        for(int i = 3; i <= n; i++){
            while(v[i] < v[i - 1]){
                v[i] += v[i - 1];
                op.pb({i, i - 1});
            }
        }
    }

    cout << op.size() << endl;
    for(auto u: op)
        cout << u.fi << ' ' << u.se << endl;
}

int main(){
    get_input();
    while(t--)
        solve();
}
