#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int dp[2] = {nums[0], nums[1]}; 
        for(int i = 2; i < n; i++) {
            int _d0 = dp[0];
            dp[0] = max(dp[0], dp[1]);
            dp[1] = nums[i] + _d0;
        }

        return max(dp[0], dp[1]);
    }
};