#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;

        auto trans = [](int &x) -> int {
            int ans = 0;
            while(x) {
                int m = x % 10;
                ans += m * m;
                x /= 10;
            }

            return ans;
        };

        while(n != 1 and !us.contains(n)) {
            us.insert(n);
            n = trans(n);
        }

        return n == 1;
    }
};