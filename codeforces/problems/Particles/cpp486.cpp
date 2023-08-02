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

ll solve(){
	ll n, ans1 = 0, ans2 = 0;

	cin >> n;
	vector<ll> v(n + 1);
    bool allneg = 1;

	for(int i = 1; i <= n; i++){
		cin >> v[i];
        if(v[i] > 0) allneg = false;
    }

    if(allneg){
        ll maxx = -inf;
        for(int i = 1; i <= n; i++)
            maxx = max(maxx, v[i]);

        return maxx;
    }

	for(int i = 1; i <= n; i += 2)
        ans1 += max(0ll, v[i]);
	
	for(int i = 2; i <= n; i += 2)
        ans2 += max(0ll, v[i]);
       
	return max(ans1, ans2);
}

int main(){
    get_input();
    while(t--)
	    cout << solve() << endl;
}
