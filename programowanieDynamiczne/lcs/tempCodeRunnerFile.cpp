for(int i = 1 ; i <= m; i++)
    {
        if(dp[n][i - 1] < dp[n][i]) ans.push_back(i - 1);
    }