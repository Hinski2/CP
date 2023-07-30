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
    int n, diff1, diff2;
    string str1, str2;

    cin >> n;
    cin >> str1 >> str2;

    diff1 = 0;
    for(int i = 0; i < n; i++)
        if(str1[i] != str2[i]) diff1++;
    diff2 = 0;
    for(int i = 0; i < n; i++)
        if(str1[i] != str2[n - i - 1]) diff2++;

    if(diff1 == 0) return 0;
    if(diff2 == 0) return 2;
    diff1 = diff1 * 2 - diff1 % 2;
    diff2 = diff2 * 2 - (1 - diff2 % 2);

    return min(diff1, diff2);
}

int main(){
    get_input();
    while(t--)
        cout << solve() << endl;
}
