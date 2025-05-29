#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int energy = nums[0] - 1;
        for(int i = 1; i < nums.size(); i++) {
            if(energy < 0) return 0;
            energy = max(energy, nums[i]) - 1;
        }

        return true;
    }
};