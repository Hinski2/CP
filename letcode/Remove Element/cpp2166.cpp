#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i = 0; i < nums.size();) {
            if(nums[i] == val) {
                swap(nums[i], nums.back());
                nums.pop_back();
            } else {
                i++;
            }
        }

        return nums.size();
    }
};
