#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define open 0
#define close 1

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

struct interval{
    int pos;
    int type;
    int idx;
};

int n, closed;
set<int> open;
vector<int> include, is_included;
vector<interval> vec;

//does a should stay before b
bool cmp(interval a, interval b){
    if(a.pos != b.pos) return a.pos < b.pos;
    return b.close == close;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    include.resize(n);
    is_included.resize(n);

    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        vec.pb({a, open, i});
        vec.pb({b, close, i});
    }

    sort(vec.begin(), vec.end(), cmp);
    for(auto u: vec){
        open.insert({

    
}
