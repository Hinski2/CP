#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 1, energy = nums[0];
        int best = 0;

        if(nums.size() == 1) return 0;

        for(int i = 1; i < nums.size(); i++) {
            energy--;
            best = max(best - 1, nums[i]);

            if(energy == 0 and i + 1 < nums.size()) {
                energy = best;
                ans++;
            }
        }

        return ans;
    }
};