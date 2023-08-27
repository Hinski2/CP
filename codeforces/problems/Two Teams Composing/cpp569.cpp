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

bool check(int no, int n, vector<int> &sum){
    int no_different = 0, maxx = 0;
    for(int i = 0; i <= n; i++){
        if(sum[i]) no_different++;
        maxx = max(maxx, sum[i]);
    }

    bool ans = no_different - 1 >= no && maxx >= no;
    ans |= no_different >= no && maxx - 1 >= no;

    return ans;
}

int solve(){
    int n;
    cin >> n;

    vector<int> sum(n + 1);
    for(int i = 0, x; i < n; i++){
        cin >> x;
        sum[x]++;
    }

    int l = 0, r = n, mid;
    while(l < r){
        mid = (l + r + 1) / 2;
        if(check(mid, n, sum))
            l = mid;
        else
            r = mid - 1;
    }

    return (l + r + 1) / 2;
}

int main(){
    get_input();
    while(t--)
        cout << solve() << endl;
}
