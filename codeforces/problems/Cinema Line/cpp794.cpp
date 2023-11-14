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

int n, rest[101];
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
}

bool solve(){
    while(n--){
        int x; cin >> x;
        if(x == 25) rest[25]++;

        if(x == 50){
            if(rest[25]) rest[25]--, rest[50]++;
            else return 0;
        }

        if(x == 100){
            if(rest[25] && rest[50]) rest[25]--, rest[50]--, rest[100]++;
            else if(rest[25] > 2) rest[25] -= 3, rest[100]++;
            else return 0;
        }
    }
    return 1;
}
    
int main(){
    get_input();
    cout << (solve() ? "YES" : "NO") << endl;
}
