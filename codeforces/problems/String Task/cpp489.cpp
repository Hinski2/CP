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

int diff = 'a' - 'A';
bool samo['z' + 1];
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    samo['a'] = samo['o'] = samo['e'] = samo['y'] = samo['u'] = samo['i'] = 1;
}

void make(){
    string s;
    vector<char> v;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
        if(s[i] < 'a') s[i] += diff;
    for(auto u: s)
        if(!samo[u]) v.pb(u);
    for(auto u: v)
        cout << '.' << u;
    cout << endl;
}

int main(){
    get_input();
    make();
}
