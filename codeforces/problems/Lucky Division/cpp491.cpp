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
const int mak = 1000 + 7;

int n;
bool lucky[10];
vector<int>Div;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
}

void find_Div(){
    for(int i = 1; i <= sqrt(n); i++)
        if(n % i == 0){
            Div.pb(i);
            Div.pb(n / i);
        }
}

bool sprawdzenie(int x){
    while(x){
        if(!lucky[x % 10]) return 0;
        x /= 10;
    }

    return 1;
}

int main(){
    get_input();
    find_Div();

    lucky[4] = lucky[7] = 1;
    for(auto u: Div)
        if(sprawdzenie(u)){
            cout << "YES\n";
            return 0;
        }
    cout << "NO\n";
}
