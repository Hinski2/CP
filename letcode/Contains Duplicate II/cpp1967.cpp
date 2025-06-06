#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, int> um;

public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        um.reserve(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            add(i, nums, k);
            if(ok(nums[i])) return 1;
        }

        return 0;
    }

    inline void add(int idx, vector<int> &nums, int k) {
        um[nums[idx]]++;

        if (idx > k) {
            auto& front = nums[idx - k - 1];
            um[front]--;
        }
    }

    bool ok(int val) {
        return um[val] >= 2;
    }
};
