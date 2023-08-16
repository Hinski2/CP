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

inline int no(char c){
    return c - '0';
}

bool solve(){
    ll n;
    string s, l, r;

    vector<vector<int>> pos(10);
    cin >> s >> n >> l >> r;

    for(int i = 0; i < s.size(); i++)
        pos[no(s[i])].pb(i);

    for(int i = 0, idx = 0, next_idx = 0; i < n; i++){
        for(int j = l[i] - '0'; j <= r[i] - '0'; j++){
            auto position = lower_bound(pos[j].begin(), pos[j].end(), idx);
            if(position == pos[j].end()) return true;
            next_idx = max(next_idx, *position + 1);
        }

        idx = next_idx;
    }

    return false;
}

int main(){
    get_input();
    while(t--)
        cout << (solve() ? "YES" : "NO") << endl;
}
