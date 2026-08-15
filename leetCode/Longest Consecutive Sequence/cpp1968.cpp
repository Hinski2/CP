#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
unordered_map<int, int> dp;
int ans = 0;

public:
    int longestConsecutive(vector<int>& nums) {
        for(auto u: nums)
            dp[u] = 0;

        for(auto [k, _]: dp)
            if(dp[k] == 0) dfs(k);

        return ans;
    }

    void dfs(int v) {
        dp[v] = 1;
        if(dp.count(v + 1)) {
            if(dp[v + 1] == 0) dfs(v + 1);
            dp[v] += dp[v + 1];
        }

        ans = max(ans, dp[v]);
    }
};
