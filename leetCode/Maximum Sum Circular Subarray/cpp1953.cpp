#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& v) {
            int n = v.size();
            vector<int> suf(n);
    
            int subAns = v[n - 1];
            suf[n - 1] = v[n - 1];
            for(int i = n - 2; i >= 0; i--) {
                subAns += v[i];
                suf[i] = max(suf[i + 1], subAns);
            }
    
            int ans = -1e9, pref = 0;
            subAns = 0;

            for(int i = 0; i + 1 < n; i++) {
                pref += v[i];
                subAns = max(subAns + v[i], v[i]);

                ans = max(ans, subAns);
                ans = max(ans, pref + suf[i + 1]);
            }
    
            // n - 1
            subAns = max(subAns + v[n - 1], v[n - 1]);
            ans = max(ans, subAns);
    
            return ans;
        }
    };