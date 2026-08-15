#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0, nums.size() - 1, nums);
    }

    TreeNode* solve(int l, int r, vector<int>& nums) {
        int size = r - l + 1;
        if(size == 1) return new TreeNode(nums[l]);
        if(size == 2) return new TreeNode(nums[r], solve(l, r - 1, nums), nullptr);

        int mid = (l + r) / 2;
        TreeNode* l_child = solve(l, mid - 1, nums);
        TreeNode* r_child = solve(mid + 1, r, nums);
        return new TreeNode(nums[mid], l_child, r_child);
    }
};