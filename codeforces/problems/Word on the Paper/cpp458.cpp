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
const int mak = 8;

int t;
string ans;
char m[mak + 1][mak + 1];

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int i = 0; i <= mak; i++)
        for(int j = 0; j <= mak; j++)
            m[i][j] = '.';
}

void search(int i, int j){
    ans = ans + m[i][j];
    if(m[i + 1][j] != '.')
        search(i + 1, j);
}

void solve(){
    bool found = false;
    for(int i = 0; i < mak; i++)
        for(int j = 0; j < mak; j++)
            cin >> m[i][j];

    for(int i = 0; i < mak && !found; i++)
        for(int j = 0;j < mak && !found; j++)
            if(m[i][j] != '.'){
                search(i, j);
                found = true;
            }
}

int main(){
    get_input();
    while(t--){
        ans = "";
        solve();
        cout << ans << '\n';
    }
}
