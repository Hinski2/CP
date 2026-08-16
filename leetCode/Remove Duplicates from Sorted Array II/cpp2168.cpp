#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insert_to = 1, same_cnt = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] == nums[i]) same_cnt++;
            else same_cnt = 1;
            
            if(same_cnt <= 2) {
                nums[insert_to++] = nums[i];
            }
        }

        return insert_to;
    }
};
