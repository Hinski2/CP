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

ll n, budget;
ll min_koszt;

vector<ll> v;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> budget;
    v.resize(n);
    for(auto &u: v) cin >> u;
}

bool sprawdz(int k){
    vector<ll> cena(n);
    for(ll i = 0; i < n; i++)
        cena[i] = v[i] + (i + 1) * k;
    sort(all(cena));

    ll suma = 0;
    for(ll i = 0; i < k; i++)
        suma += cena[i];

    if(suma <= budget) min_koszt = suma;
    return suma <= budget;
}
int main(){
    get_input();
    int l = 0, r = n, mid;
    while(l < r){
        mid = (l + r + 1) / 2;
        if(sprawdz(mid))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << ' ' << min_koszt << endl;
}
