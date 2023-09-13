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

inline int no(char s){
    return s - '0';
}

void solve(){
    string s; cin >> s;
    s = '0' + s;
    int idx = s.size();

    for(int i = s.size() - 1; i > 0; i--)
        if(no(s[i]) > 4) s[i - 1]++, idx = i;
    for(int i = (no(s[0]) == 0); i < s.size(); i++)
        cout << (i < idx ? no(s[i]) : 0);
    cout << endl;
}

int main(){
    get_input();
    while(t--)
        solve();
}
