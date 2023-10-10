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

int n;
string s;
vector<int> ans;
vector<vector<int>> lista(10);

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
}

void dodaj_do_listy(){
    lista[2] = {2};
    lista[3] = {3};
    lista[4] = {3, 2, 2};
    lista[5] = {5};
    lista[6] = {5, 3};
    lista[7] = {7};
    lista[8] = {7, 2, 2, 2};
    lista[9] = {7, 3, 3, 2};
}

void solve(int x){
    for(auto u: lista[x]) ans.pb(u);
}
int main(){
    get_input();
    dodaj_do_listy();
    for(auto u: s) solve(u - '0');

    sort(all(ans), greater<int>());
    for(auto u: ans) cout << u;

    cout << endl;
}
