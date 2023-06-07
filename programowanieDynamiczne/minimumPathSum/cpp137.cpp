#include <bits/stdc++.h>
using namespace std;

int n, m;
int G[1005][1005];
int dp[1005][1005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin>>G[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i == 1) dp[i][j] = dp[i][j - 1] + G[i][j];
            else if(j == 1) dp[i][j] = dp[i - 1][j] + G[i][j];
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + G[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}