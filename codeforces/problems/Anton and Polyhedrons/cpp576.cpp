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

int n;
map<string, int>mapa;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    mapa["Tetrahedron"] = 4;
    mapa["Cube"] = 6;
    mapa["Octahedron"] = 8;
    mapa["Dodecahedron"] = 12;
    mapa["Icosahedron"] = 20;

    cin >> n;
}
int main(){
    get_input();

    int ans = 0;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        ans += mapa[s];
    }

    cout << ans << endl;
}
