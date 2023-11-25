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
const int inf = 1e8 + 7;
const int mak = 517;

int n, m, k;
vector<int> lekcje[mak];
int mini[mak][mak], dp[mak][mak];

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            if(c == '1') lekcje[i].pb(j);
        }

    for(int i = 0; i < mak; i++)
        for(int j = 0; j < mak; j++)
            mini[i][j] = dp[i][j] = inf;
}

void policz_mini(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            int sajz = lekcje[i].size();
            if(j == sajz)
                mini[i][j] = 0;
            if(j < sajz)
                for(int l = 0; l <= j; l++){
                    int r = j - l;
                    mini[i][j] = min(mini[i][j], lekcje[i][sajz - r - 1] - lekcje[i][l] + 1);
                }
        }
    }
}

int policz_dp(){
    for(int i = 0; i <= k; i++)
        dp[0][i] = mini[0][i];

    for(int i = 1; i < n; i++)
        for(int j = 0; j <= k; j++)
            for(int w = 0; w <= j; w++)
                    dp[i][j] = min(dp[i][j], dp[i - 1][w] + mini[i][j - w]); 
                
    int ans = INT_MAX;
    for(int i = 0; i <= k; i++)
        ans = min(ans, dp[n - 1][i]);
    return ans;
}

int main(){
    get_input();
    policz_mini();
    cout << policz_dp() << endl;
}
