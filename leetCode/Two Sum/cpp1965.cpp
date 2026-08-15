#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++) {
            if(um.contains(target - nums[i])) {
                ans[0] = i;
                ans[1] = um[target - nums[i]];
                break;
            }

            um[nums[i]] = i;
        }        
    
        return ans;
    }
};