#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> ans = nums;

        for(int i = 0; i < nums.size(); i++) {
            int pos = i - k;
            if(pos < 0) pos = nums.size() + pos;

            ans[i] = nums[pos];
        }

        nums = ans;
    }
};