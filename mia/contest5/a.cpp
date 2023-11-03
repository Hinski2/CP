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

int n, l, x, y;
int ans1 = 1, ans2 = 1;
vector<int> v;
set<int> s1, s2;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l >> x >> y;
    v.resize(n);
    for(auto &u: v) cin >> u;
    sort(all(v));
}

set<int> fi, se;
int main(){
    get_input();
    for(auto u: v){
        if(u >= x && fi.count(u - x)) ans1 = 0;

        if(u + x <= l) s1.insert(x + u);
        if(u >= x) s1.insert(u - x);
        fi.insert(u);
    }
    for(auto u: v){
        if(u >= y && se.count(u - y)) ans2 = 0;

        if(u + y <= l) s2.insert(y + u);
        if(u >= y) s2.insert(u - y);
        se.insert(u);
    }

    if(ans1 && ans2){
        for(auto u: s1)
            if(s2.count(u)){
                cout << 1 << endl;
                cout << u << endl;
                return 0;
            }
        cout << 2 << endl;
        cout << *s1.begin() << ' ' << *s2.begin() << endl;
    }
    else if(ans1){
        cout << 1 << endl;
        cout << *s1.begin() << endl;
    }
    else if(ans2){
        cout << 1 << endl;
        cout << *s2.begin() << endl;
    }
    else{
        cout << 0 << endl;
    }
}
