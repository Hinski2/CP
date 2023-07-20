#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back

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
const int mak = 3;

int t;
char m[3][3];

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

bool sprawdz(char c){
    if(m[0][0] == c && m[1][1] == c && m[2][2] == c) return 1;
    if(m[0][2] == c && m[1][1] == c && m[2][0] == c) return 1;

    for(int i = 0; i < mak; i++)
        if(m[i][0] == c && m[i][1] == c && m[i][2] == c) return 1;
    for(int i = 0; i < mak; i++)
        if(m[0][i] == c && m[1][i] == c && m[2][i] == c) return 1;

    return 0;
}

void solve(){
    for(int i = 0; i < mak; i++)
        for(int j = 0; j < mak; j++)
            cin >> m[i][j];

    if(sprawdz('X'))
        cout << "X\n";
    else if(sprawdz('O'))
        cout << "O\n";
    else if(sprawdz('+'))
        cout << "+\n";
    else
        cout << "DRAW\n";
}

int main(){
    get_input();
    while(t--)
        solve();
}
