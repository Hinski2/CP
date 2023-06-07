//oblicz na ile sposobów możesz się dostać na n schodek przy k skokach
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int suma[1005];

int n, k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    
    dp[0][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 2][j - 1];
            suma[i] += dp[i][j];
        }
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
