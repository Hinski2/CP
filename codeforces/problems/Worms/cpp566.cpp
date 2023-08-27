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

int n, t;
vector<int> v;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    v.resize(n + 1);
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        v[i] = v[i - 1] + x;
    }

    cin >> t;
}

int find(int pos){
    int l = 1, r = n, mid;
    while(l < r){
        mid = (l + r) / 2;
        if(v[mid] >= pos)
            r = mid;
        else
            l = mid + 1;
    }

    return (l + r) / 2;
}

int main(){
    get_input();
    for(int i = 0, pos; i < t; i++){
        cin >> pos;
        cout << find(pos) << endl;
    }
}
