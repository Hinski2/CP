#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

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
vector<bool> prime(mak, 1);

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

void solve(){
    int n;
    list<int> l;
    cin >> n;

    l.push_back(1);
    for(int i = n; i >= 2; i--){
        l.push_back(i--);

        if(i == 1) break;
        l.push_front(i);
    }

    for(auto u: l)
        cout << u << ' ';
    cout << '\n';
}

void sito(){
    for(int i = 2; i * i < mak; i++){
        if(!prime[i]) continue;
        for(int j = i * i; j < mak; j += i)
            prime[j] = false;
    }
}

int main(){
    get_input();
    sito();

    while(t--)
        solve();
}
