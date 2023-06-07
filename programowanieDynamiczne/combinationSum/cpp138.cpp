#include <bits/stdc++.h>
using namespace std;

int ile, target;
int dp[1005];

vector<int>nums;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>target>>ile;
    for(int i = 1; i <= ile; i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }

    dp[0] = 1;

    for(int i = 0; i < target; i++)
    {
        for(auto u: nums)
        {
            dp[i + u] += dp[i];
        }
    }

    cout<<dp[target]<<"\n";
}