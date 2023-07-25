#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

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

bool solve(){
    int n, k;
    cin >> n >> k;

    vector<int> vec(n + 1);
    int fi, la;

    for(int i = 1; i <= n; i++)
        cin >> vec[i];
    fi = vec[1];
    la = vec[n];

    if(fi == la){
        for(int i = 1, cnt = 0; i <= n; i++){
            if(vec[i] == fi) cnt++;
            if(cnt == k) return 1;
        }
    }

    int ostatni = inf, pierwszy = inf;
    for(int i = 1, cnt = 0; i <= n; i++){
        if(vec[i] == fi) cnt++;
        if(cnt == k){
            ostatni = i;
            break;
        }
    }
    for(int i = n, cnt = 0; i > 0; i--){
        if(vec[i] == la) cnt++;
        if(cnt == k){
            pierwszy = i;
            break;
        }
    }

    if(ostatni == inf || pierwszy == inf) return false;
    return ostatni < pierwszy;
}

int main(){
    get_input();
    while(t--)
        cout << (solve() ? "YES\n" : "NO\n");
}
