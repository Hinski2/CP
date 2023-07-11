#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 1e5 + 5;

int n, m;
ll dp[mak][105], value[mak];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()

    //get data
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> value[i];


    if(value[1] == 0)
        for(int i = 1; i <= m; i++) dp[1][i] = 1;
    else
        dp[1][value[1]] = 1;

    for(int i = 2; i <= n; i++){
        if(value[i] == 0)
            for(int j = 1; j <= m; j++){
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] += dp[i - 1][j];
                dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= mod;
            }
        else{
            dp[i][value[i]] += dp[i - 1][value[i] - 1];
            dp[i][value[i]] += dp[i - 1][value[i]];
            dp[i][value[i]] += dp[i - 1][value[i] + 1];
            dp[i][value[i]] %= mod;
        }
    }

    ll ans = 0;
    for(int i = 1; i <= m; i++){
        ans += dp[n][i];
        ans %= mod;
    }

    cout << ans << '\n';
}
