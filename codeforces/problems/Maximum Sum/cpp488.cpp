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

ll solve(){
	int n, k;
	cin >> n >> k;

	vector<int> v(n + 2);
	for(int i = 1; i <= n; i++)
		cin >> v[i];

	sort(v.begin() + 1, v.end() - 1);
	ll sumAll = 0;
	for(auto u: v)
		sumAll += u;

	ll suml = 0, l = 0;
	ll sumr = 0, r = n + 1;
	for(; l <= 2 * k; l++)
		suml += v[l];
	l--;
	ll ans = 0;	
	while(l){
		ans = max(ans, sumAll - suml - sumr);
		suml -= v[l--];
		suml -= v[l--];
		sumr += v[--r];
	}

    ans = max(ans, sumAll - suml - sumr);
	return ans;
}
int main(){
    get_input();
    while(t--)
	    cout << solve() << endl;
}
