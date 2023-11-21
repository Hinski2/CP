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

int n, m;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
}

void sprawdz(int &a, int &b, int x){
    a = 0, b = 0;
    int _n = n, _m = m;

    while(_n % x == 0){
        a++;
        _n /= x;
    }
    while(_m % x == 0){
        b++;
        _m /= x;
    }

    for(int i = 0; i < b - a; i++)
        n *= x;
}

int main(){
    get_input();
    if(m % n){
        cout << -1 << endl;
        return 0;
    }

    int a, b, ans = 0;
    sprawdz(a, b, 2);
    ans += b - a;

    sprawdz(a, b, 3);
    ans += b - a;

    if(m != n){
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
}
