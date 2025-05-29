#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool maj(vector<int>& v, int val) {
            int cnt = 0;
            for(auto u: v) {
                if(u == val) cnt++;
            }

            return 2 * cnt > v.size();
        }

        int majorityElement(vector<int>& nums) {
            int pos = 0, size = nums.size();
            vector<int> original = nums;

            while(size > 1) {
                pos = 0;
                for(int i = 0; i < size; i += 2) {
                    if(nums[i] == nums[i + 1]) {
                        nums[pos++] = nums[i];
                    } 
                }

                if(size % 2) {
                    if(maj(original, nums[size - 1]))
                        return nums[size - 1];
                }
                
                size = pos;
            }

            return nums[0];
        }
    };