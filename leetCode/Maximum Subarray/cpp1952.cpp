#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int get_mini(vector<int>& nums) {
        int mini = 1e9;
        for(auto u: nums)
            mini = min(mini, u);

        return mini;
    }

    int maxSubArray(vector<int>& nums) {
        int ans = get_mini(nums), sub_ans = 0;

        for(auto u: nums) {
            sub_ans = max(u, sub_ans + u);
            ans = max(sub_ans, ans);
        }  

        return ans;
    }
};