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

int t, n;
vector<int> ans(205), Next(205);
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

int find(int v, int p, int no){
    if(v == p) return ans[v] = no;
    
    no++;
    return ans[v] = find(Next[v], p, no);
}

int main(){
    get_input();
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> Next[i];
            ans[i] = 0;
        }
        for(int i = 1; i <= n; i++)
            if(!ans[i]) ans[i] = find(Next[i], i, 1);
        for(int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
}
