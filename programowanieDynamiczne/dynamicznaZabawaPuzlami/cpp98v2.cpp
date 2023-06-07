#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;
const int mod = 1e9 + 7;

int n;
int dp[mak][3];

int prosty(int m);
int wkl(int m);
int wyp(int m);

int oblicz(int m)
{
    int ans = 0;

    if(m == 1)
    {
        return 1;
    }
    else
    {
        ans = (ans + prosty(m)) % mod;
        ans = (ans + wkl(m)) % mod;
        ans = (ans + wyp(m)) % mod;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    cout<<oblicz(n)<<"\n";
}

int prosty(int m)
{
    if(dp[m][0])
    {
        return dp[m][0];
    }
    else
    {
        dp[m][0] = (dp[m][0] + prosty(m - 1)) % mod;

        if(m > 2)
        {
            dp[m][0] = (dp[m][0] + wkl(m - 1)) % mod;
            dp[m][0] = (dp[m][0] + wyp(m - 1)) % mod;
        }
    }

    return dp[m][0]; 
}

int wyp(int m)
{
    if(dp[m][1])
    {
        return dp[m][1];
    }
    else
    {
        dp[m][1] = (dp[m][1] + prosty(m - 1)) % mod;

        if(m > 2)
        {
            dp[m][1] = (dp[m][1] + wkl(m - 1)) % mod;
        }
    }

    return dp[m][1];
}

int wkl(int m)
{
    if(dp[m][2])
    {
        return  dp[m][2];
    }
    else
    {
        dp[m][2] = (dp[m][2] + prosty(m - 1)) % mod;

        if(m > 3)
        {
            dp[m][2] = (dp[m][2] + (2 * wyp(m - 2) % mod)) % mod;
        }
    }

    return dp[m][2];
}