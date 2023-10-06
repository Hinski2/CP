#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define pb push_back
 
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
const int mak = 105;
 
int n, ile[4][10];
 
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1, x; j <= 6; j++)
            cin >> x, ile[i][x]++;
}
 
bool sprawdz(int x){
    vector<int> used;
    while(x){
        used.pb(x % 10);
        x /= 10;
    }
    
    for(int i = 1; i < 4; i++)
        for(int j = 1; j < 4; j++)
            for(int k = 1; k < 4; k++){
                if(i == j || j == k || i == k) continue;
                if(used.size() > 0 && !ile[i][used[0]]) continue;
                if(used.size() > 1 && !ile[j][used[1]]) continue;
                if(used.size() > 2 && !ile[k][used[2]]) continue;
                return true;
            }
    return false;
}
 
int main(){
    get_input();
    for(int i = 1; i < 1000; i++)
        if(!sprawdz(i)){
            cout << i  - 1 << endl;
            return 0;
        }
}