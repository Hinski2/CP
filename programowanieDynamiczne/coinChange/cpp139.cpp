#include <bits/stdc++.h>
using namespace std;

int n, ile;
int dp[1005];

vector<int>nums;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>ile;

    for(int i = 1; i <= ile; i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }

    for(int i = 0; i <= 1000; i++) dp[i] = 1e9 + 7;

    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        for(auto u: nums)
        {
            dp[i + u] = min(dp[i + u], dp[i] + 1);
        }
    }

    for(int i = 0; i <= n; i++)
    {
        cout<<i<<" "<<dp[i]<<endl;
    }

}