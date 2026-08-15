#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, mini = 1e9 + 7;
        for(auto u: prices) {
            mini = min(mini, u);
            ans = max(ans, u - mini);
        }
        return ans;
    }
};
