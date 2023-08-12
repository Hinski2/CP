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

bool ban[mak];
string s;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
}

bool solve1(){
    bool found = false;
    for(int i = 1; i < s.size() && !found; i++)
        if(s[i] == 'A' && s[i - 1] == 'B'){
            ban[i] = ban[i - 1] = true;
            found = true;
        }

    if(!found) return 0;
    found = false;

    for(int i = 1; i < s.size() && !found; i++){
        if(ban[i] || ban[i - 1]) continue;
        if(s[i] == 'B' && s[i - 1] == 'A')
            found = true;
    }

    return found;
}

bool solve2(){
    for(int i = 0; i < mak; i++)
        ban[i] = false;

    bool found = false;
    for(int i = 1; i < s.size() && !found; i++)
        if(s[i] == 'B' && s[i - 1] == 'A'){
            ban[i] = ban[i - 1] = true;
            found = true;
        }

    if(!found) return 0;
    found = false;

    for(int i = 1; i < s.size() && !found; i++){
        if(ban[i] || ban[i - 1]) continue;
        if(s[i] == 'A' && s[i - 1] == 'B')
            found = true;
    }

    return found;
}

int main(){
    get_input();
    cout << (solve1() || solve2() ? "YES" : "NO") << endl;
}
