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
    int n, ans = 0, minWin = inf;
    cin >> n;

    vector<int> v(n + 1), minele(n + 1);
    minele[0] = inf;

    for(int i = 1; i <= n; i++){
        cin >> v[i];
        minele[i] = min(minele[i - 1], v[i]);
    }

    for(int i = 1; i <= n; i++){
        //pregrywa
        if(v[i] <= minele[i])
            continue;
        //nadal przegrywa
        else if(v[i] > minWin)
            continue;
        //wygrywa
        else{
            ans++;
            minWin = min(minWin, v[i]);
        }
    }
    return ans;
}

int main(){
    get_input();
    while(t--)
        cout << solve() << endl;
}
