#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int move_to_idx = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] != nums[i]) {
                nums[move_to_idx++] = nums[i];
            }
        }           

        return move_to_idx;
    }
};
