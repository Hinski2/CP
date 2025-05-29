#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;

        int l = 0, r = 0;
        while(l < m and r < n) {
            if(nums1[l] < nums2[r]) {
                ans.push_back(nums1[l++]);
            } else {
                ans.push_back(nums2[r++]);
            }
        }

        while(l < m) {
            ans.push_back(nums1[l++]);
        }

        while(r < n) {
            ans.push_back(nums2[r++]);
        }

        nums1 = ans;
    }
};