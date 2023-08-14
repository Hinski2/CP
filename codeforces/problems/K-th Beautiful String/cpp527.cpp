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
const int mak = 1e5 + 5;

int t;
vector<ll> sum(mak);

void make_sum(){
    for(int i = 1; i < mak; i++)
        sum[i] = sum[i - 1] + i;
}

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

void solve(){
    int n, k;
    cin >> n >> k;

    int l = 0, r = n, mid;
    while(l < r){
        mid = (l + r + 1) / 2;
        if(k > sum[mid])
            l = mid;
        else
            r = mid - 1;
    }
    l++; r++;

    l = n - l; 
    r = n - (k - sum[r - 1] - 1);

    for(int i = 1; i <= n; i++){
        if(i == r || i == l) cout << 'b';
        else cout << 'a';
    }

    cout << endl;
}

int main(){
    get_input();
    make_sum();

    while(t--)
        solve();
}
