#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1, amm = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(amm == 1 and nums[i - 1] == nums[i]) {
                nums[idx++] = nums[i];
                amm = 2;
            } else if (amm == 1 and nums[i - 1] != nums[i]) {
                nums[idx++] = nums[i];
            } else if (amm == 2 and nums[i - 1] != nums[i]) {
                nums[idx++] = nums[i];
                amm = 1;
            }
        }      

        return idx;
    }
};