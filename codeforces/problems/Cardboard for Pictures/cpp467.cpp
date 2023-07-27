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

ll sprawdz(ll mid, ll w, vector<ll> &vec){
    ll sum = 0;
    for(auto u: vec){
        sum += (u + 2 * mid) * (u + 2 * mid);
        if(sum > w) return sum;
    }

    return sum;
}

ll solve(){
    ll n, w;
    cin >> n >> w;

    vector<ll> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i];

    ll l = 1, r = 2e9, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(sprawdz(mid, w, vec) < w)
            l = mid + 1;
        else if(sprawdz(mid, w, vec) > w)
            r = mid - 1;
        else 
            return mid;
    }

    return 0; 
} 

int main(){
    get_input();
    while(t--)
        cout << solve() << endl;
}
