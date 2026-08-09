#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        auto idx1 = 0, idx2 = 0;

        while(idx1 < m and idx2 < n) {
            if(nums1[idx1] < nums2[idx2]) ans.push_back(nums1[idx1++]);
            else ans.push_back(nums2[idx2++]);
        }

        while(idx1 < m)
            ans.push_back(nums1[idx1++]);

        while(idx2 < n)
            ans.push_back(nums2[idx2++]);

        nums1 = std::move(ans);
    }
};
