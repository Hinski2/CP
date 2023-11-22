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

int n, fig[20][20];
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
}
int main(){
    get_input();
    for(int i = 0; i <= n; i++){
        fig[i][n] = i;
        for(int j = n - 1, w = i - 1; j >= 0; j--, w--)
            fig[i][j] = w;
        for(int j = n + 1, w = i - 1; j <= 2 * n; j++, w--)
            fig[i][j] = w;
    }
    for(int i = n + 1; i <= 2 * n; i++){
        fig[i][n] = 2 * n - i;
        for(int j = n - 1, w = 2 * n - i - 1; j >= 0; j--, w--)
            fig[i][j] = w;
        for(int j = n + 1, w = 2 * n - i - 1; j <= 2 * n; j++, w--)
            fig[i][j] = w;
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 2 * n; j++){
            if(fig[i][j] == 0 && j >= n) cout << fig[i][j];
            else if(fig[i][j] >= 0) cout << fig[i][j] << ' ';
            else if(j <= n) cout << "  ";
        }
        cout << endl;
    }
    for(int i = n + 1; i <= 2 * n; i++){
        for(int j = 0; j <= 2 * n; j++){
            if(fig[i][j] == 0 && j >= n) cout << fig[i][j];
            else if(fig[i][j] >= 0) cout << fig[i][j] << ' ';
            else if(j <= n) cout << "  ";
        }

        cout << endl;
    }
}
