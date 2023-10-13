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

int n, p[2];
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> p[0] >> p[1];
}
int main(){
    get_input();
    char c;
    int ans = 0, last = 2;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == '*') last = 2;
        else{
            if(last == 2 && p[0] > p[1] && p[0]) p[0]--, ans++, last = 0;
            else if(last == 2 && p[0] <= p[1] && p[1]) p[1]--, ans++, last = 1;
            else if(last == 1 && p[0]) p[0]--, last = 0, ans++;
            else if(last == 0 && p[1]) p[1]--, last = 1, ans++;
            else if(last == 1 && !p[0]) last = 2;
            else if(last == 0 && !p[1]) last = 2;
        }
    }
    cout << ans << endl;
}
