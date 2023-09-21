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

int solve(){
    string s; cin >> s;
    int noA = 0, noB = 0;

    if(s[0] == 'A') noA++;
    if(s[0] == 'B') noB++;

    for(int i = 1; i < s.size(); i++){
        if(s[i] == 'A' && s[i - 1] != 'A') noA++;
        if(s[i] == 'B') noB++;
    }

    if(noA == 0 || noB == 0) return 0;
    if(noA <= noB){
        int no = 0;
        for(auto u: s)
            if(u == 'A') no++;
        return no;
    }

    int Min = inf, now = 0, no = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A') now++, no++;
        if(s[i] == 'B') Min = min(Min, now), now = 0;
    }

    Min = min(Min, now);
    return no - Min;
}
int main(){
    get_input();
    while(t--)
        cout << solve() << endl;

}
