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
const int mak = 1e6 + 5;

int t;
vector<bool> snow(mak + 5);
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

void make_snow(){
    for(ll i = 2; i < mak; i++){
        ll node = i * i + i, vert = i * i;

        while(node < mak){
            snow[node + 1] = true;
            node += vert * i;
            vert *= i;
        } 
    }
}

int main(){
    get_input();
    make_snow();
    for(int i = 0, x; i < t; i++){
        cin >> x;
        cout << (snow[x] ? "YES" : "NO") << endl;
    }
}
