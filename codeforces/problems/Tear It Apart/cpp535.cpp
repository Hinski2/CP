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
vector<int>op(mak);

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

void make_operations(){
    op[1] = 1;
    for(int i = 2; i < mak; i++)
        op[i] = 1 + op[i / 2];
}

int solve(){
    string s;
    vector<int> subAns(alf), pos(alf, -1);

    cin >> s;
    for(int i = 0; i < (int)s.size(); i++){
        subAns[s[i]] = max(subAns[s[i]], op[i - pos[s[i]] -1]);
        pos[s[i]] = i;
    }

    int ans = inf;
    for(int i = 'a'; i <= 'z'; i++){
        subAns[i] = max(subAns[i], op[(int)s.size() - pos[i] - 1]);
        ans = min(ans, subAns[i]);
    }

    return ans;
}

int main(){
    get_input();
    make_operations();
    while(t--)
        cout << solve() << endl;
}
