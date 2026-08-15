#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<int> vis;
    vector<int> generate_bits(int x, int n) {
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(vis.count(x ^ (1 << i))) continue;
            ans.push_back(x ^ (1 << i));
        }

        return ans;
    }

    vector<int> grayCode(int n) {
        vector<int> ans;
        int x = 0;

        auto moves = generate_bits(x, n);
        while(moves.size()) {
            ans.push_back(x);
            vis.insert(x);

            x = moves[0];
            moves = generate_bits(x, n);
        }

        ans.push_back(x);

        return ans;
    }
};