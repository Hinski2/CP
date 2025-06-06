#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
unordered_set<int> us;

public:
    int longestConsecutive(vector<int>& nums) {
        for(auto u: nums) {
            us.insert(u); 
        }

        int ans = 0, now;
        for(auto k: us) {
            if(us.contains(k - 1)) continue; 
            now = 1; 

            while(us.contains(k + 1)) {
                now++;
                k++;
            }

            ans = max(ans, now);
        }

        return ans;
    }
};
